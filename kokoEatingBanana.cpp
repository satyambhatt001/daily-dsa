bool canFinish(vector<int>& piles, int speed, int h) {

    long long hours = 0;

    for(int bananas : piles) {

        // convert to double so normal division happens (not integer division)
        // ceil() rounds UP to the nearest integer
        //
        // Example: 7 / 4 = 1.75  --> ceil(1.75) = 2
        hours += ceil((double)bananas / speed);
    }

    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {

    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int ans = right;

    while(left <= right) {

        int mid = left + (right - left) / 2;

        if(canFinish(piles, mid, h)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}




//2nd approach bruteforce

bool canFinish(vector<int>& piles, int speed, int h) {

    long long hours = 0;

    for(int bananas : piles) {
        hours += ceil((double)bananas / speed);
    }

    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {

    // find maximum pile
    int maxi = *max_element(piles.begin(), piles.end());

    // try every speed from 1 to maxi
    for(int speed = 1; speed <= maxi; speed++) {

        if(canFinish(piles, speed, h)) {
            return speed;   // return first speed that works
        }
    }

    return maxi;   // fallback (should never reach)
}


