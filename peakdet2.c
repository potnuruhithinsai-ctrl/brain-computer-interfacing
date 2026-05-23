#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
   DO NOT MODIFY BELOW THIS LINE
*/

#define N 1000
#define MAX_PEAKS 50
#define PEAK_THRESHOLD 0.6f   // not used in this method, kept as given


float rand_float(float min, float max) {
    return min + (float)rand() / RAND_MAX * (max - min);
}


/*
   Peak detection using Moving Average
   Deviation Threshold = 0.5f
*/
void detect_peak_stream(float sample, int index, int detected_peaks[]) {

    #define MA_WINDOW 5
    #define DEVIATION_THRESHOLD 0.5f

    /* Static variables retain state between calls
       enabling real-time (streaming) processing */
    static float buffer[MA_WINDOW] = {0};
    static int buf_index = 0;
    static int count = 0;
    static float sum = 0.0f;

    /* Remove oldest sample from running sum */
    sum -= buffer[buf_index];

    /* Store new sample in circular buffer */
    buffer[buf_index] = sample;
    sum += sample;

    /* Update circular buffer index */
    buf_index = (buf_index + 1) % MA_WINDOW;

    /* Wait until enough samples are available */
    if (count < MA_WINDOW) {
        count++;
        return;
    }

    /* Compute moving average */
    float moving_avg = sum / MA_WINDOW;

    /* Peak detection condition:
       current sample deviates significantly
       from local moving average */
    if (sample > moving_avg + DEVIATION_THRESHOLD) {
        detected_peaks[index] = 1;
    }
}


/*
   DO NOT MODIFY BELOW THIS LINE
*/

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

        /* Streaming peak detection */
        detect_peak_stream(eeg[i], i, detected_peaks);
    }

    /* Evaluation */
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
