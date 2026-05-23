#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
   DO NOT MODIFY BELOW THIS LINE */


#define N 1000
#define MAX_PEAKS 50
#define PEAK_THRESHOLD 0.6f


float rand_float(float min, float max) {
    return min + (float)rand() / RAND_MAX * (max - min);
}


// TASK: COMPLETE THIS FUNCTION
void detect_peak_stream(float sample, int index, int detected_peaks[]) {
 static float prev = 0.0f;      // sample at index (i-1)
    static float pastprev = 0.0f;  // sample at index (i-2)

    /* Peak detection requires at least three samples:
       previous-previous, previous, and current */
    if (index >= 2) {

        /* A peak is detected if:
           1.rising  
           2.falling  
           3.exceeds the threshold */
        if (prev > pastprev &&
            prev > sample &&
            prev > PEAK_THRESHOLD) {

           
            detected_peaks[index - 1] = 1;
        }
    }

    /* Update samples for the next  call */
    pastprev = prev;
    prev = sample;

    // TO DO
    // WRITE LOGIC TO DETECT PEAKS
}


// DO NOT MODIFY BELOW THIS LINE


int main() {
    float eeg[N];
    int true_peaks[N] = {0};
    int detected_peaks[N] = {0};


    srand(time(NULL));


    printf("Simulating EEG samples...\n");


    for (int i = 0; i < N; i++) {


        /* Generate baseline EEG */
        eeg[i] = rand_float(0.1f, 0.2f);


        /* Randomly insert peaks */
        if (rand() % 100 < 4) {   // ~4% chance
            eeg[i] = rand_float(0.7f, 1.0f);
            true_peaks[i] = 1;
        }
        detect_peak_stream(eeg[i], i, detected_peaks);
    }


    // EVALUATION
    int true_positive = 0;
    int false_positive = 0;
    int false_negative = 0;
    int total_peaks = 0;


    for (int i = 0; i < N; i++) {
        if (true_peaks[i])
            total_peaks++;


        if (true_peaks[i] && detected_peaks[i])
            true_positive++;
        else if (!true_peaks[i] && detected_peaks[i])
            false_positive++;
        else if (true_peaks[i] && !detected_peaks[i])
            false_negative++;
    }




    printf("Total samples     : %d\n", N);
    printf("Actual peaks      : %d\n", total_peaks);
    printf("True positives    : %d\n", true_positive);
    printf("False positives   : %d\n", false_positive);
    printf("False negatives   : %d\n", false_negative);


    return 0;
}

