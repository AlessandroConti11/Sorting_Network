import matplotlib.pyplot as plt
import numpy as np
import csv

def ls3_sort(n):
    return 9 * n

def mergesort_4way(n):
    return 7 * n

def rotatesort(n):
    return 10 * n + 8 * np.sqrt(n)

def schnorr_shamir(n):
    return 3 * n + 7 * n**(3/4) + n**(1/4)


def shearsort(n):
    return n * (np.log2(n) + 3) - 2

# Range di n
n_values = np.arange(1, 211, 1)

# Calcolo valori
ls3_vals = ls3_sort(n_values)
merge4_vals = mergesort_4way(n_values)
rotate_vals = rotatesort(n_values)
schnorr_vals = schnorr_shamir(n_values)
shearsort_vals = shearsort(n_values)



vertical_line = []
for i in range(len(n_values)):
    if shearsort_vals[i] > rotate_vals[i]:
        vertical_line.append(n_values[i])
        print(f"shearsort - rotatesort {n_values[i]} - {shearsort_vals[i]}, {rotate_vals[i]}")
        break
for i in range(len(n_values)):
    if shearsort_vals[i] > ls3_vals[i]:
        vertical_line.append(n_values[i])
        print(f"shearsort - ls3 {n_values[i]} - {shearsort_vals[i]}, {ls3_vals[i]}")
        break
for i in range(len(n_values)):
    if shearsort_vals[i] > merge4_vals[i]:
        vertical_line.append(n_values[i])
        print(f"shearsort - 4way-mergesort {n_values[i]} - {shearsort_vals[i]}, {merge4_vals[i]}")
        break
for i in range(len(n_values)):
    if shearsort_vals[i] > schnorr_vals[i]:
        vertical_line.append(n_values[i])
        print(f"shearsort - 3n {n_values[i]} - {shearsort_vals[i]}, {schnorr_vals[i]}")
        break
for i in range(len(n_values)):
    if merge4_vals[i] > schnorr_vals[i]:
        vertical_line.append(n_values[i])
        print(f"4way-mergesort - 3n {n_values[i]} - {merge4_vals[i]}, {schnorr_vals[i]}")
        break

# Plot
plt.figure(figsize=(12, 6))
plt.plot(n_values, ls3_vals, label="LS3-Sort", linestyle='-', color='red')
plt.plot(n_values, merge4_vals, label="4-Way Mergesort", linestyle='-', color='green')
plt.plot(n_values, rotate_vals, label="Rotatesort", linestyle='-', color='blue')
plt.plot(n_values, schnorr_vals, label="3n-Sort (Schnorr-Shamir)", linestyle='-', color='magenta')
plt.plot(n_values, shearsort_vals, label="Shearsort", linestyle='-', color='cyan')

for x in vertical_line:
    plt.axvline(x=x, color='gray', linestyle='--')

plt.title("Sorting Network Complexity")
plt.xlabel("n")
plt.ylabel("Complexity")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.margins(x=0.01)
plt.margins(y=0.01)
plt.show()




with open("sorting_algorithms_data.csv", "w", newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(["x", "y_ls3", "y_merge4", "y_rotate", "y_schnorr", "y_shear"])
    for i in range(len(n_values)):
        writer.writerow([
            n_values[i],
            ls3_vals[i],
            merge4_vals[i],
            rotate_vals[i],
            schnorr_vals[i],
            shearsort_vals[i]
        ])
with open("vertical_line.csv", "w", newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(["x", "y0", "y1"])
    for x in vertical_line:
        writer.writerow([x, 0, 2300])