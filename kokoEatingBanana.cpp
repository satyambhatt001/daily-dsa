
// ---------------------------------------------------------
// Function: canFinish
// Purpose:  Check whether Koko can finish all bananas
//           if she eats with a given speed "speed"
//           within "h" hours.
// ---------------------------------------------------------
bool canFinish(vector<int>& piles, int speed, int h) {

    long long hours = 0;      // total hours needed (long long so it never overflows)

    // loop through each pile of bananas
    for(int bananas : piles) {

        // We need ceil(bananas / speed)
        // Example: bananas = 7, speed = 4
        // real value = 1.75 → ceil = 2 hours
        //
        // Formula: (bananas + speed - 1) / speed
        // This avoids floating point math.
        hours += (bananas + speed - 1) / speed;
    }

    // if total hours is LESS THAN OR EQUAL to allowed hours,
    // then speed is enough
    return hours <= h;
}

// ---------------------------------------------------------
// Function: minEatingSpeed
// Purpose:  Find the MINIMUM eating speed at which
//           Koko finishes all bananas in h hours.
//           We use Binary Search on speed.
// ---------------------------------------------------------
int minEatingSpeed(vector<int>& piles, int h) {

    int left = 1;   // smallest possible speed (eat 1 banana/hour)

    // right = largest pile
    // if speed is at least this, Koko can finish that pile in 1 hour
    int right = *max_element(piles.begin(), piles.end());

    int ans = right;    // store best (minimum valid) speed found

    // Standard binary search loop
    while(left <= right) {

        // mid = current guessed speed
        int mid = left + (right - left) / 2;

        // If Koko CAN finish using speed = mid
        if(canFinish(piles, mid, h)) {

            ans = mid;          // store this as possible answer
            right = mid - 1;    // try to see if slower speed also works
        }

        // If she CANNOT finish in time,
        // speed must be increased
        else {
            left = mid + 1;
        }
    }

    // return the smallest speed that worked
    return ans;
}


