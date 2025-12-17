import subprocess
import matplotlib.pyplot as plt

sizes = [10, 50, 100, 200, 500, 1000]
operations = []

for n in sizes:
    # Génère une liste aléatoire de taille n
    numbers = " ".join(str(i) for i in range(n, 0, -1))  # exemple: liste inversée
    # Lance ton programme C
    result = subprocess.run(
        ["./push_swap", numbers], capture_output=True, text=True
    )
    # Récupère le nombre d'opérations (stdout)
    op_count = int(result.stdout.strip())
    operations.append(op_count)

# Tracer la courbe
plt.plot(sizes, operations, marker="o")
plt.xlabel("Taille de la liste")
plt.ylabel("Nombre d'opérations")
plt.title("Benchmark push_swap")
plt.grid(True)
plt.show()
