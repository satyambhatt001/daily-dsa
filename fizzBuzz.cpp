vector<string> fizzBuzz(int n) {
    vector<string> ans;

    for (int i = 1; i <= n; i++) {

        // divisible by both 3 and 5
        if (i % 15 == 0) // if(i%3==0 && i%5==0)
            ans.push_back("FizzBuzz");

        // divisible by only 3
        else if (i % 3 == 0)
            ans.push_back("Fizz");

        // divisible by only 5
        else if (i % 5 == 0)
            ans.push_back("Buzz");

        // normal number
        else
            ans.push_back(to_string(i));
    }

    return ans;
}
