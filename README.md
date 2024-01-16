### Edward Ramos - personal demonstration

# Directed Graph

The input file is formatted in the format of the first line including first the size of the graph along with 1 byte alphabetized character labels of each vertex done through the subsequent letters of the rest of the line after numeric size.
The rest of the 2D row matrix will then be iterated through starting with the first listed vertices in order of the first line and iterating through every value of the adjacency matrix showing either true for a given edge relationship between the current row and the current column, or false if there exists no relationship between the current row and the current column. The program expects this formatted input, however can be redone to include additional error checking and potential input anomalies beyond the scope of this quick demo. The graph structure will be constructed via this input file where a print and recursive depth-first search algorithm can be performed.
Input data was auto-generated and may include loops or cycles during path traversal. See adjacency_list.txt for example.
