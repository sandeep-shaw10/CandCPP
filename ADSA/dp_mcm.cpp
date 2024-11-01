#include<bits/stdc++.h>
using namespace std;


char letter = 'A';


// Function to perform matrix chain multiplication and return the cost and parenthesization
int matrixChainOrder(const vector<int>& p, int n, vector<vector<int>>& m, vector<vector<int>>& s) {
    // m[i][i] is zero since a single matrix doesn't need multiplication
    for (int chainLength = 2; chainLength <= n; ++chainLength) {
        for (int i = 0; i < n - chainLength + 1; ++i) {
            int j = i + chainLength - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                // Calculate q as the cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;  // Store the index of the split point
                }
            }
        }
    }
    return m[0][n - 1];
}


// Function to print the parenthesization
void printParenthesization(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << letter++ ; // Matrix indexing starts at 1 for display
    } else {
        cout << "(";
        printParenthesization(s, i, s[i][j]);
        printParenthesization(s, s[i][j] + 1, j);
        cout << ")";
    }
}


int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    vector<int> dimensions;

    // Read the dimensions from the file
    getline(inputFile, line);
    inputFile.close();

    // Remove brackets
    string cleanedLine;
    for (char ch : line) {
        if (ch != '[' && ch != ']') {
            cleanedLine += ch;
        }
    }

    stringstream ss(cleanedLine);
    int value;

    while (ss >> value) {
        dimensions.push_back(value);
        if (ss.peek() == ' ') ss.ignore();
    }

    // Number of matrices
    int n = dimensions.size() - 1;

    // Create MCM table and split table
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    // Call the function and display the result
    int minMultiplications = matrixChainOrder(dimensions, n, m, s);

    // Output the minimum number of multiplications
    cout << "Minimum number of multiplications is: " << minMultiplications << endl;

    // Output the MCM table
    cout << "\nCost Table:" << endl;
    for (const auto& row : m) {
        for (const auto& val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }

    // Output the MCM table
    cout << "\ns-table:" << endl;
    for (const auto& row : s) {
        for (const auto& val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }

    // Output the parenthesized result
    cout << "\nOptimal Parenthesization: ";
    printParenthesization(s, 0, n - 1);
    cout << endl;

    return 0;
}
