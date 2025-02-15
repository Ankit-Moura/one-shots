from qiskit import QuantumCircuit, Aer, transpile
from qiskit.visualization import plot_bloch_vector
import matplotlib.pyplot as plt
import numpy as np

# Function to simulate and get Bloch vector
def get_bloch_vector(circuit):
    simulator = AerSimulator()
    transpiled_circuit = transpile(circuit, simulator)
    result = simulator.run(transpiled_circuit).result()
    return result.data()["statevector"].bloch_vector(0)

# Create a quantum circuit with 1 qubit
qc = QuantumCircuit(1)

# List of gates we will apply
gates = ["h", "y", "z", "h", "x", "y", "z"]

# Apply gates and visualize after each step
for i, gate in enumerate(gates):
    if gate == "h":
        qc.h(0)
    elif gate == "x":
        qc.x(0)
    elif gate == "y":
        qc.y(0)
    elif gate == "z":
        qc.z(0)
    
    # Get new Bloch vector
    bloch_vector = get_bloch_vector(qc)
    
    # Plot it
    plt.figure(figsize=(5, 5))
    plot_bloch_vector(bloch_vector)
    plt.title(f"Step {i+1}: Applied {gate.upper()} Gate")
    plt.show()
