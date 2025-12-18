/* int maxProfit(vector<int>&prices){
    int minPrice=INT_MAX;
    int maxProfit=0;
    for(int i=0;i<prices.size();i++){
        minPrice=min(minPrice,prices[i]);
        maxProfit=max(maxProfit,prices[i]-minPrice);
    }
    return maxProfit;
} */

#include <bits/stdc++.h>   // Include all standard C++ libraries
using namespace std;

// Function to calculate maximum profit
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;   // Initialize minPrice to a very large number (infinity)
                               // This will track the lowest stock price seen so far
    int maxProfit = 0;        // Initialize maxProfit to 0
                               // This will store the maximum profit achievable

    // Loop through each day's price
    for (int i = 0; i < prices.size(); i++) {
        // Update minPrice if current price is smaller than minPrice
        minPrice = min(minPrice, prices[i]);

        // Calculate profit if we sell today (current price - minPrice seen so far)
        // Update maxProfit if this profit is greater than previous maxProfit
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    // Return the maximum profit found
    return maxProfit;
}

int main() {
    ios::sync_with_stdio(false);  // Disable synchronization between C and C++ I/O
                                  // Speeds up input/output operations
    cin.tie(nullptr);             // Untie cin from cout, further improving I/O speed

    int n;                        
    cout << "Enter number of days: ";
    cin >> n;                     // Read number of days (size of prices array)

    vector<int> prices(n);         // Create a vector to store stock prices for each day
    cout << "Enter prices for each day: ";
    for (int i = 0; i < n; i++) 
        cin >> prices[i];          // Read the stock prices into the vector

    int profit = maxProfit(prices);  // Call the function to calculate maximum profit

    cout << "Maximum profit: " << profit << "\n";  // Print the result

    return 0;                       // End of program
}
