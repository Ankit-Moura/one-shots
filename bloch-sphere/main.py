from qiskit.visualization import plot_bloch_vector
import matplotlib.pyplot as plt

# Define a qubit state using (x, y, z) coordinates
bloch_vector = [0.7, 0.4, 0.8] 

plot_bloch_vector(bloch_vector)
plt.show()
