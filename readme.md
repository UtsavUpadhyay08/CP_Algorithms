## Execution with Input and Output Files

To run the compiled C++ program with input from a text file and store the output in another text file, follow these steps:

1.  Compile the C++ file:

    ```bash
    g++ <path_to_cpp_file> -o <output_executable_name>
    ```

    Example:

    ```bash
    g++ ./codeforces_sol.cpp -o ./codeforces_sol
    ```

2.  Run the program with input and output redirection:

    ```bash
    <output_executable_name> < <path_to_input_file> > <path_to_output_file>
    ```

    Example:

    ```bash
    ./codeforces_sol < ./input.txt > ./output.txt
    ```

    This will run the program with input.txt as the input file and save the output to output.txt.
