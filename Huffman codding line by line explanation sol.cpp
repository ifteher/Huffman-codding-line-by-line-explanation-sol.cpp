// In the name of ALLAH
#include <bits/stdc++.h> // Includes all necessary libraries
using namespace std;

// Optimization for faster input and output
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Defining shorthand macros for convenience
#define ll long long int           // Shorthand for long long int
#define all(v) v.begin(), v.end()  // Shorthand for accessing the entire vector
#define rall(v) v.rbegin(), v.rend() // Shorthand for accessing the vector in reverse order
#define enl '\n'                   // Shorthand for newline
#define pub push_back              // Shorthand for push_back
#define pob pop_back               // Shorthand for pop_back
#define input(v, s, e) for (ll i = s; i <= e; i++) cin >> v[i]; // Input vector elements
#define output(v) for (ll i = 0; i < v.size(); i++) cout << v[i] << " "; // Output vector elements
#define loop(s, e) for (ll i = s; i <= e; i++) // Shorthand for a for-loop from s to e
// Function to compute the hash code of a substring [l, r]
ll hash_code(string s, ll l, ll r) {
    ll prime = 3, power = 1;  // Prime base and initial power
    ll hash_codee = 0;        // Variable to store hash value
    for (ll i = l; i <= r; i++) {
        // Convert character to a number and multiply by current power
        hash_codee += (s[i] - 'a' + 1) * power;
        power *= prime;       // Increase power for next character
    }
    return hash_codee;        // Return the final hash value
}
// Function to compute the hash code of the current substring
ll current_hash_code(string s, ll pre_hash_code, ll l, ll r) {
    ll prime = 3; // Same prime base as in `hash_code`
    // Remove the contribution of the character leaving the window
    ll hash_codee = pre_hash_code - (s[l - 1] - 'a' + 1);
    hash_codee /= prime; // Divide the remaining hash by the prime base
    // Add the contribution of the new character entering the window
    hash_codee += ((s[r] - 'a' + 1) * pow(prime, r - l));
    return hash_codee; // Return updated hash value
}
void solve() {
    string text, pattern; // Input text and pattern
    cin >> text >> pattern;

    ll n = text.size(), m = pattern.size(); // Length of text and pattern
    // Compute the hash of the pattern
    ll pattern_hash_code = hash_code(pattern, 0, m - 1), sub_text_hash_code;
    vector<ll> starting_index; // Store starting indices of matches

    ll pre_hash_code = 0; // Store the previous hash code for rolling hash
    for (int i = 0; i <= n - m; i++) { // Iterate through all possible substrings
        if (i == 0) {
            // Compute hash for the first substring
            sub_text_hash_code = hash_code(text, 0, m - 1);
            if (pattern_hash_code == sub_text_hash_code) {
                starting_index.push_back(i); // Add starting index if hashes match
            }
        } else {
            // Use rolling hash to compute current substring hash
            sub_text_hash_code = current_hash_code(text, pre_hash_code, i, i + m - 1);
            if (pattern_hash_code == sub_text_hash_code) {
                starting_index.push_back(i); // Add starting index if hashes match
            }
        }
        pre_hash_code = sub_text_hash_code; // Update previous hash
    }

    // Output results
    if (starting_index.empty()) {
        cout << "not found" << enl; // If no matches are found
    } else {
        cout << "string is found and starting indices are:" << enl;
        for (auto u : starting_index) cout << u << " "; // Print all starting indices
        cout << enl;
    }
}
int main() {
    optimize(); // Optimize input/output
    int t = 1; // Number of test cases (default is 1)
    while (t--) {
        solve(); // Solve each test case
    }
    return 0; // Return 0 to indicate successful execution
}



* Testcase:
Input:
ababcabc
abc
Output:string is found and starting indices are:
2 5
