::: container
# 🧮 Matrix Factorization and Determinant Calculation

This C++ project implements matrix factorization using LU decomposition,
calculates the determinant of matrices, and measures execution time,
optimizing performance with OpenMP for parallelism.

## 🔍 LU Decomposition

-   Utilizes OpenMP for parallelism to optimize performance.
-   Factors a given matrix `A` into lower (`L`) and upper (`U`)
    triangular matrices.
-   Calculates `L` and `U` matrices for each row iteratively.

## 💡 Benefits & Considerations

-   **Efficient parallel computation** using OpenMP for large matrices.
-   **Memory management**: Properly deallocates memory after use.
-   **Scalability**: Performs well for matrix sizes ranging from 1000 to
    100000.

## 📈 Use Cases

-   Linear algebra applications such as solving systems of linear
    equations.
-   Scientific simulations requiring matrix manipulation and analysis.

## ⚙️ Serial vs Parallel Execution

Serial execution involves running instructions sequentially, while
parallel execution divides tasks for simultaneous processing on multiple
threads or cores.

## 📝 Main Function

The main function serves as the entry point, measures computation time,
generates random matrices, performs LU decomposition, calculates the
determinant, and prints results while managing memory efficiently.

## 🚀 Parallelization using OpenMP

The code uses OpenMP directives to parallelize loops, enhancing
efficiency by dividing tasks across multiple threads, while ensuring
smooth operation through proper variable management.

## 💬 How to Get Started

Clone the repository, compile the code with OpenMP support, and run the
executable to start experimenting with different matrix sizes and
observing the performance benefits of parallel computation.

## 🤝 Contributing

Contributions to improve efficiency and functionality are welcome. Feel
free to fork the repository, make changes, and submit a pull request.

Thank you for visiting this project! We hope it provides valuable
insights into matrix factorization and determinant calculation using
parallel computing techniques.
