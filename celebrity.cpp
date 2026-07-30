// You are given N people at a party.

// You are also given a matrix M where:

// M[i][j] = 1  → Person i knows Person j
// M[i][j] = 0  → Person i does NOT know Person j

// Your task is to find the celebrity.

// A celebrity is a person who satisfies both conditions:

// The celebrity knows nobody.
// Everybody else knows the celebrity.

// If such a person exists, return their index.

// Otherwise, return -1.
//       0 1 2
//     --------
// 0 |   0 1 1
// 1 |   0 0 1
// 2 |   0 0 0

// Read the matrix

// Person 0 knows:

// Person 1
// Person 2

// Person 1 knows:

// Person 2

// Person 2 knows:

// Nobody

// Now check each person.

// Person 0

// Knows people.

//  Cannot be celebrity.

// Person 1

// Knows person 2.

//Cannot be celebrity.

// Person 2

// Knows nobody 

// Does everyone know person 2?

// Person 0 knows 2 
// Person 1 knows 2 

// So person 2 is the celebrity.

// Answer = 2



// 1st approach brute force
// Time complexity: O(N^2)
// Space complexity: O(1)
int celebrity(vector<vector<int>> &M, int n) {
    for (int i = 0; i < n; i++) {
        bool isCelebrity = true;
        for (int j = 0; j < n; j++) {
            if (i != j) {
               // Condition 1:
            // Celebrity should not know anyone
            // Condition 2:
            // Everyone should know the celebrity
                if (M[i][j] == 1 || M[j][i] == 0) {
                    isCelebrity = false;
                    break;
                }

            }
        }
        if (isCelebrity) {
            return i; // Found the celebrity
        }
    }
    return -1; // No celebrity found
}

//2nd approach using two pointer
// Time complexity: O(N)
// Space complexity: O(N)

int celebrity(vector<vector<int>> &M, int n) {
    int a = 0;
    int b = n - 1;

    while (a < b) {
        if (M[a][b] == 1) {
            // a knows b, so a cannot be celebrity
            a++;
        } else {
            // a does not know b, so b cannot be celebrity
            b--;
        }
    }

    // Now a is the only candidate for celebrity
    for (int i = 0; i < n; i++) {
        if (i != a) {
            // Check if a knows anyone or if anyone doesn't know a
            if (M[a][i] == 1 || M[i][a] == 0) {
                return -1; // Not a celebrity
            }
        }
    }

    return a; // Found the celebrity
}
