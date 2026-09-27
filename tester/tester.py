#!/usr/bin/env python3
import os
import sys
import time
import csv
import json
import random
import re
import statistics
import subprocess
import argparse
import zipfile
from datetime import datetime

from rich.console import Console
from rich.panel import Panel
from rich.progress import Progress, SpinnerColumn, BarColumn, TextColumn, TimeElapsedColumn, MofNCompleteColumn
from rich.table import Table
from rich import print as rprint

console = Console()

def get_binary_path():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    root_dir = os.path.abspath(os.path.join(script_dir, ".."))
    binary = os.path.join(root_dir, "push_swap")
    
    if not os.path.exists(binary):
        console.print(Panel("[bold yellow]Binário 'push_swap' não encontrado. Compilando com 'make'...[/bold yellow]"))
        res = subprocess.run(["make", "-C", root_dir], capture_output=True, text=True)
        if res.returncode != 0 or not os.path.exists(binary):
            console.print("[bold red]Erro ao compilar o push_swap com make:[/bold red]")
            console.print(res.stderr)
            sys.exit(1)
        console.print("[bold green]Compilação concluída com sucesso![/bold green]\n")
    return binary

def simulate_push_swap(stack, ops_lines):
    a = list(stack)
    b = []
    
    for op in ops_lines:
        op = op.strip()
        if not op:
            continue
        if op == "sa" and len(a) >= 2:
            a[0], a[1] = a[1], a[0]
        elif op == "sb" and len(b) >= 2:
            b[0], b[1] = b[1], b[0]
        elif op == "ss":
            if len(a) >= 2: a[0], a[1] = a[1], a[0]
            if len(b) >= 2: b[0], b[1] = b[1], b[0]
        elif op == "pa" and b:
            a.insert(0, b.pop(0))
        elif op == "pb" and a:
            b.insert(0, a.pop(0))
        elif op == "ra" and a:
            a.append(a.pop(0))
        elif op == "rb" and b:
            b.append(b.pop(0))
        elif op == "rr":
            if a: a.append(a.pop(0))
            if b: b.append(b.pop(0))
        elif op == "rra" and a:
            a.insert(0, a.pop())
        elif op == "rrb" and b:
            b.insert(0, b.pop())
        elif op == "rrr":
            if a: a.insert(0, a.pop())
            if b: b.insert(0, b.pop())
            
    return (len(b) == 0 and a == sorted(stack))

def parse_test_outputs(stdout_str, stderr_str):
    ops_info = {
        "total_ops": 0,
        "sa": 0, "sb": 0, "ss": 0,
        "pa": 0, "pb": 0,
        "ra": 0, "rb": 0, "rr": 0,
        "rra": 0, "rrb": 0, "rrr": 0
    }
    
    combined_lines = (stderr_str + "\n" + stdout_str).strip().splitlines()
    raw_ops_lines = []
    
    for line in combined_lines:
        line_str = line.strip()
        if line_str.startswith("[bench] total_ops:"):
            try:
                ops_info["total_ops"] = int(line_str.split(":")[-1].strip())
            except ValueError:
                pass
        elif line_str.startswith("[bench]") and "sa:" in line_str:
            matches = re.findall(r"(sa|sb|ss|pa|pb):\s*(\d+)", line_str)
            for op, val in matches:
                ops_info[op] = int(val)
        elif line_str.startswith("[bench]") and "ra:" in line_str:
            matches = re.findall(r"(ra|rb|rr|rra|rrb|rrr):\s*(\d+)", line_str)
            for op, val in matches:
                ops_info[op] = int(val)
        elif not line_str.startswith("[bench]") and line_str in ["sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"]:
            raw_ops_lines.append(line_str)
            ops_info[line_str] += 1

    if ops_info["total_ops"] == 0 and raw_ops_lines:
        ops_info["total_ops"] = len(raw_ops_lines)

    return ops_info, raw_ops_lines

def run_single_test(binary, stack, algo_flag):
    cmd = [binary, algo_flag, "--bench"] + [str(x) for x in stack]
    start_time = time.perf_counter()
    res = subprocess.run(cmd, capture_output=True, text=True)
    end_time = time.perf_counter()
    
    exec_time_ms = (end_time - start_time) * 1000.0
    
    if res.returncode != 0:
        return {
            "success": False,
            "sorted": False,
            "ops": 0,
            "time_ms": exec_time_ms,
            "ops_detail": {},
            "error": res.stderr
        }
    
    ops_info, raw_ops_lines = parse_test_outputs(res.stdout, res.stderr)
    is_sorted = simulate_push_swap(stack, raw_ops_lines)
    
    return {
        "success": True,
        "sorted": is_sorted,
        "ops": ops_info["total_ops"],
        "time_ms": exec_time_ms,
        "ops_detail": ops_info
    }

def col_to_name(col):
    name = ''
    while col > 0:
        col, remainder = divmod(col - 1, 26)
        name = chr(65 + remainder) + name
    return name

def make_sheet_xml(rows):
    xml = ['<?xml version="1.0" encoding="UTF-8" standalone="yes"?>',
           '<worksheet xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main">',
           '<sheetData>']
    for r_idx, row in enumerate(rows, 1):
        xml.append(f'<row r="{r_idx}">')
        for c_idx, val in enumerate(row, 1):
            cell_ref = f'{col_to_name(c_idx)}{r_idx}'
            if isinstance(val, (int, float)):
                xml.append(f'<c r="{cell_ref}"><v>{val}</v></c>')
            elif isinstance(val, bool):
                xml.append(f'<c r="{cell_ref}"><v>{"TRUE" if val else "FALSE"}</v></c>')
            else:
                val_str = str(val).replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;')
                xml.append(f'<c r="{cell_ref}" t="inlineStr"><is><t>{val_str}</t></is></c>')
        xml.append('</row>')
    xml.append('</sheetData></worksheet>')
    return ''.join(xml)

def save_multi_sheet_xlsx(filepath, sheets_dict):
    sheet_names = list(sheets_dict.keys())
    if not sheet_names:
        return

    with zipfile.ZipFile(filepath, "w", compression=zipfile.ZIP_DEFLATED) as zf:
        ct_lines = [
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>',
            '<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">',
            '<Default Extension="rels" ContentType="application/vnd.openxmlformats-package.relationships+xml"/>',
            '<Default Extension="xml" ContentType="application/xml"/>',
            '<Override PartName="/xl/workbook.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml"/>',
            '<Override PartName="/xl/styles.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml"/>'
        ]
        for i in range(1, len(sheet_names) + 1):
            ct_lines.append(f'<Override PartName="/xl/worksheets/sheet{i}.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml"/>')
        ct_lines.append('</Types>')
        zf.writestr('[Content_Types].xml', ''.join(ct_lines))

        rels = [
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>',
            '<Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">',
            '<Relationship Id="rId1" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument" Target="xl/workbook.xml"/>',
            '</Relationships>'
        ]
        zf.writestr('_rels/.rels', ''.join(rels))

        wb_lines = [
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>',
            '<workbook xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships">',
            '<sheets>'
        ]
        for i, sname in enumerate(sheet_names, 1):
            wb_lines.append(f'<sheet name="{sname}" sheetId="{i}" r:id="rId{i}"/>')
        wb_lines.append('</sheets></workbook>')
        zf.writestr('xl/workbook.xml', ''.join(wb_lines))

        wb_rels = [
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>',
            '<Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">'
        ]
        for i in range(1, len(sheet_names) + 1):
            wb_rels.append(f'<Relationship Id="rId{i}" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/worksheet" Target="worksheets/sheet{i}.xml"/>')
        styles_rid = len(sheet_names) + 1
        wb_rels.append(f'<Relationship Id="rId{styles_rid}" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles" Target="styles.xml"/>')
        wb_rels.append('</Relationships>')
        zf.writestr('xl/_rels/workbook.xml.rels', ''.join(wb_rels))

        styles_xml = (
            '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>'
            '<styleSheet xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main">'
            '<fonts count="1"><font><sz val="11"/><name val="Calibri"/></font></fonts>'
            '<fills count="1"><fill><patternFill patternType="none"/></fill></fills>'
            '<borders count="1"><border/></borders>'
            '<cellStyleXfs count="1"><xf numFmtId="0" fontId="0" fillId="0" borderId="0"/></cellStyleXfs>'
            '<cellXfs count="1"><xf numFmtId="0" fontId="0" fillId="0" borderId="0" xfId="0"/></cellXfs>'
            '</styleSheet>'
        )
        zf.writestr('xl/styles.xml', styles_xml)

        for i, sname in enumerate(sheet_names, 1):
            rows_data = []
            records = sheets_dict[sname]
            if records:
                headers = list(records[0].keys())
                rows_data.append(headers)
                for rec in records:
                    rows_data.append([rec.get(h, "") for h in headers])
            else:
                rows_data.append(["Status"])
                rows_data.append(["Nenhum teste executado ainda para este algoritmo."])

            sheet_xml = make_sheet_xml(rows_data)
            zf.writestr(f'xl/worksheets/sheet{i}.xml', sheet_xml)

def prompt_user_inputs():
    console.print(Panel.fit("[bold cyan]Push Swap - Testador Automatizado CLI[/bold cyan]", border_style="cyan"))
    
    console.print("[bold]Escolha o modo de teste:[/bold]")
    console.print("  [1] Tamanho fixo (Testar pilha N de tamanho fixo K vezes)")
    console.print("  [2] Progressivo (Iterar de 1 em 1 até N_máximo)")
    
    mode_choice = input("➔ Opção (1-2) [Padrão: 2]: ").strip()
    is_progressive = (mode_choice != "1")

    if is_progressive:
        while True:
            try:
                max_n_str = input("➔ Digite o tamanho máximo da pilha (N_max) [ex: 500]: ").strip()
                max_n = int(max_n_str)
                if max_n <= 0:
                    console.print("[red]O tamanho máximo deve ser maior que 0.[/red]")
                    continue
                break
            except ValueError:
                console.print("[red]Entrada inválida. Digite um número inteiro positivo.[/red]")
        n = max_n
        runs = 1
    else:
        while True:
            try:
                n_str = input("➔ Digite o tamanho da pilha (N): ").strip()
                n = int(n_str)
                if n <= 0:
                    console.print("[red]O tamanho da pilha deve ser maior que 0.[/red]")
                    continue
                break
            except ValueError:
                console.print("[red]Entrada inválida. Digite um número inteiro positivo.[/red]")

        while True:
            try:
                runs_str = input("➔ Digite a quantidade de testes (execuções): ").strip()
                runs = int(runs_str)
                if runs <= 0:
                    console.print("[red]A quantidade de testes deve ser maior que 0.[/red]")
                    continue
                break
            except ValueError:
                console.print("[red]Entrada inválida. Digite um número inteiro positivo.[/red]")

    console.print("\n[bold]Escolha o algoritmo:[/bold]")
    console.print("  [1] --complex (Radix Sort Binário)")
    console.print("  [2] --medium")
    console.print("  [3] --simple")
    console.print("  [4] --adaptive")
    
    algo_choice = input("➔ Digite a opção (1-4) [Padrão: 1]: ").strip()
    algo_map = {
        "1": "--complex",
        "2": "--medium",
        "3": "--simple",
        "4": "--adaptive",
        "--complex": "--complex",
        "--medium": "--medium",
        "--simple": "--simple",
        "--adaptive": "--adaptive"
    }
    algo_flag = algo_map.get(algo_choice, "--complex")
    
    return is_progressive, n, runs, algo_flag

def main():
    parser = argparse.ArgumentParser(description="Testador automatizado de performance para o Push Swap")
    parser.add_argument("-n", "--size", type=int, help="Tamanho fixo da pilha N")
    parser.add_argument("-r", "--runs", type=int, default=1, help="Número de execuções (para tamanho fixo)")
    parser.add_argument("-m", "--max-size", type=int, help="Modo progressivo: iterar de 1 em 1 até N_max")
    parser.add_argument("-a", "--algo", type=str, choices=["--simple", "--medium", "--complex", "--adaptive", "simple", "medium", "complex", "adaptive"], help="Algoritmo a ser testado")
    
    args = parser.parse_args()
    binary = get_binary_path()
    
    if args.max_size:
        is_progressive = True
        n_max = args.max_size
        runs = 1
        algo_input = args.algo or "--complex"
        algo_flag = algo_input if algo_input.startswith("--") else f"--{algo_input}"
    elif args.size:
        is_progressive = False
        n_max = args.size
        runs = args.runs
        algo_input = args.algo or "--complex"
        algo_flag = algo_input if algo_input.startswith("--") else f"--{algo_input}"
    else:
        is_progressive, n_max, runs, algo_flag = prompt_user_inputs()

    console.print(f"\n[bold green]Iniciando suíte de testes...[/bold green]")
    if is_progressive:
        console.print(f"• Modo: [cyan]Progressivo (Iterando de 1 a {n_max})[/cyan]")
        total_tests = n_max
    else:
        console.print(f"• Modo: [cyan]Tamanho Fixo (N = {n_max})[/cyan]")
        console.print(f"• Execuções: [cyan]{runs}[/cyan] rodadas")
        total_tests = runs

    console.print(f"• Algoritmo: [cyan]{algo_flag}[/cyan]\n")

    results = []
    ops_list = []
    time_list = []
    passed_count = 0
    
    with Progress(
        SpinnerColumn(),
        TextColumn("[progress.description]{task.description}"),
        BarColumn(),
        MofNCompleteColumn(),
        TimeElapsedColumn(),
        console=console
    ) as progress:
        task = progress.add_task("[yellow]Executando testes...", total=total_tests)
        
        if is_progressive:
            test_counter = 1
            for current_n in range(1, n_max + 1):
                min_range = -max(100000, current_n * 10)
                max_range = max(100000, current_n * 10)
                stack = random.sample(range(min_range, max_range), current_n)
                
                res = run_single_test(binary, stack, algo_flag)
                
                status_str = "PASSED" if res["sorted"] else "FAILED"
                if res["sorted"]:
                    passed_count += 1
                    
                ops_list.append(res["ops"])
                time_list.append(res["time_ms"])
                
                test_record = {
                    "test_id": test_counter,
                    "stack_size": current_n,
                    "algorithm": algo_flag.replace("--", ""),
                    "total_ops": res["ops"],
                    "sorted": res["sorted"],
                    "execution_time_ms": round(res["time_ms"], 3),
                    "sa": res["ops_detail"].get("sa", 0),
                    "sb": res["ops_detail"].get("sb", 0),
                    "ss": res["ops_detail"].get("ss", 0),
                    "pa": res["ops_detail"].get("pa", 0),
                    "pb": res["ops_detail"].get("pb", 0),
                    "ra": res["ops_detail"].get("ra", 0),
                    "rb": res["ops_detail"].get("rb", 0),
                    "rr": res["ops_detail"].get("rr", 0),
                    "rra": res["ops_detail"].get("rra", 0),
                    "rrb": res["ops_detail"].get("rrb", 0),
                    "rrr": res["ops_detail"].get("rrr", 0)
                }
                results.append(test_record)
                
                progress.update(task, advance=1, description=f"[yellow]Pilha N={current_n}/{n_max} - Ops: {res['ops']} - Status: [{'green' if res['sorted'] else 'red'}]{status_str}[/]")
                test_counter += 1
        else:
            for i in range(1, runs + 1):
                min_range = -max(100000, n_max * 10)
                max_range = max(100000, n_max * 10)
                stack = random.sample(range(min_range, max_range), n_max)
                
                res = run_single_test(binary, stack, algo_flag)
                
                status_str = "PASSED" if res["sorted"] else "FAILED"
                if res["sorted"]:
                    passed_count += 1
                    
                ops_list.append(res["ops"])
                time_list.append(res["time_ms"])
                
                test_record = {
                    "test_id": i,
                    "stack_size": n_max,
                    "algorithm": algo_flag.replace("--", ""),
                    "total_ops": res["ops"],
                    "sorted": res["sorted"],
                    "execution_time_ms": round(res["time_ms"], 3),
                    "sa": res["ops_detail"].get("sa", 0),
                    "sb": res["ops_detail"].get("sb", 0),
                    "ss": res["ops_detail"].get("ss", 0),
                    "pa": res["ops_detail"].get("pa", 0),
                    "pb": res["ops_detail"].get("pb", 0),
                    "ra": res["ops_detail"].get("ra", 0),
                    "rb": res["ops_detail"].get("rb", 0),
                    "rr": res["ops_detail"].get("rr", 0),
                    "rra": res["ops_detail"].get("rra", 0),
                    "rrb": res["ops_detail"].get("rrb", 0),
                    "rrr": res["ops_detail"].get("rrr", 0)
                }
                results.append(test_record)
                
                progress.update(task, advance=1, description=f"[yellow]Teste {i}/{runs} - Ops: {res['ops']} - Status: [{'green' if res['sorted'] else 'red'}]{status_str}[/]")

    min_ops = min(ops_list) if ops_list else 0
    max_ops = max(ops_list) if ops_list else 0
    avg_ops = statistics.mean(ops_list) if ops_list else 0.0
    med_ops = statistics.median(ops_list) if ops_list else 0.0
    avg_time = statistics.mean(time_list) if time_list else 0.0

    title_mode = f"Progressivo 1..{n_max}" if is_progressive else f"Tamanho Fixo N={n_max}"
    table = Table(title=f"Resultados dos Testes ({algo_flag} - {title_mode})", border_style="bright_blue")
    table.add_column("Métrica", style="bold cyan")
    table.add_column("Valor", style="bold white")

    table.add_row("Total de Testes Executados", str(total_tests))
    table.add_row("Taxa de Sucesso (Ordenados)", f"[{'green' if passed_count == total_tests else 'red'}]{passed_count}/{total_tests} ({passed_count/total_tests*100:.1f}%)[/]")
    table.add_row("Mínimo de Operações", f"[green]{min_ops}[/green]")
    table.add_row("Média de Operações", f"[yellow]{avg_ops:.2f}[/yellow]")
    table.add_row("Mediana de Operações", f"[yellow]{med_ops:.2f}[/yellow]")
    table.add_row("Máximo de Operações", f"[red]{max_ops}[/red]")
    table.add_row("Tempo Médio de Execução", f"{avg_time:.2f} ms")

    console.print("\n")
    console.print(table)

    script_dir = os.path.dirname(os.path.abspath(__file__))
    results_dir = os.path.join(script_dir, "results")
    os.makedirs(results_dir, exist_ok=True)
    
    current_algo_name = algo_flag.replace("--", "")
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    
    prefix = "range_1to" + str(n_max) if is_progressive else f"n{n_max}"
    csv_filename = os.path.join(results_dir, f"test_results_{current_algo_name}_{prefix}_{timestamp}.csv")
    fieldnames = list(results[0].keys()) if results else []
    
    with open(csv_filename, mode="w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(results)

    state_file = os.path.join(results_dir, "latest_results_store.json")
    sheets_store = {"simple": [], "medium": [], "complex": [], "adaptive": []}
    
    if os.path.exists(state_file):
        try:
            with open(state_file, "r", encoding="utf-8") as sf:
                existing_data = json.load(sf)
                sheets_store.update(existing_data)
        except Exception:
            pass

    sheets_store[current_algo_name] = results
    
    with open(state_file, "w", encoding="utf-8") as sf:
        json.dump(sheets_store, sf, indent=2)

    for algo_key, records in sheets_store.items():
        if records:
            algo_csv_path = os.path.join(results_dir, f"latest_results_{algo_key}.csv")
            with open(algo_csv_path, mode="w", newline="", encoding="utf-8") as f:
                w = csv.DictWriter(f, fieldnames=list(records[0].keys()))
                w.writeheader()
                w.writerows(records)

    excel_path = os.path.join(results_dir, "latest_results.xlsx")
    save_multi_sheet_xlsx(excel_path, sheets_store)

    console.print(Panel(
        f"[bold green]✔ Testes concluídos![/bold green]\n"
        f"📊 Planilha Excel Multi-Abas: [underline cyan]{excel_path}[/underline cyan]\n"
        f"   └─ Páginas/Abas: [bold white]simple | medium | complex | adaptive[/bold white]\n"
        f"📄 CSV por Algoritmo: [underline cyan]{os.path.join(results_dir, f'latest_results_{current_algo_name}.csv')}[/underline cyan]\n"
        f"📄 CSV desta Execução: [underline cyan]{csv_filename}[/underline cyan]",
        border_style="green"
    ))

if __name__ == "__main__":
    main()
