/*
 --------------------------------------------------
Project: a4q2
File:    myrecord.c
Author:  Ayaan Khan
Version: 2026-02-06
--------------------------------------------------
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "myrecord.h"
#include "mysort.h"

int cmp1(void *x, void *y) {
    float a = *(float *)x;
    float b = *(float *)y;
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

/* Not used in this solution (we sort scores instead of RECORDs),
   but keeping it is fine if your assignment expects it. */
int cmp2(void *x, void *y) {
    float a = ((RECORD *)x)->score;
    float b = ((RECORD *)y)->score;
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

GRADE grade(float score) {
    GRADE r = {"F"};

    if (score >= 90) {
        strcpy(r.letter_grade, "A");
    } else if (score >= 80) {
        strcpy(r.letter_grade, "B");
    } else if (score >= 70) {
        strcpy(r.letter_grade, "C");
    } else if (score >= 60) {
        strcpy(r.letter_grade, "D");
    }
    return r;
}

int import_data(FILE *fp, RECORD *dataset) {
    if (fp == NULL || dataset == NULL) {
        return 0;
    }

    char line[128];
    int i = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        /* CSV format: name, score  */
        if (sscanf(line, " %19[^,] , %f", dataset[i].name, &dataset[i].score) == 2) {
            i++;
        } else {
            /* stop if a line is malformed (or you could skip it) */
            break;
        }
    }
    return i;
}

STATS process_data(RECORD *dataset, int count) {
    STATS stats;

    if (dataset == NULL || count <= 0) {
        stats.count = 0;
        stats.mean = 0.0f;
        stats.stddev = 0.0f;
        stats.median = 0.0f;
        return stats;
    }

    stats.count = count;

    /* ---- mean ---- */
    float sum = 0.0f;
    for (int i = 0; i < count; i++) {
        sum += dataset[i].score;
    }
    float mean = sum / (float)count;
    stats.mean = mean;

    /* ---- stddev ---- */
    float variance_sum = 0.0f;
    for (int i = 0; i < count; i++) {
        float diff = dataset[i].score - mean;
        variance_sum += diff * diff;
    }
    stats.stddev = sqrtf(variance_sum / (float)count);

    /* ---- median ----
       We do NOT sort dataset directly (dataset is RECORD[], not void*[])
       Instead: build an array of scores and sort pointers to those scores.
    */
    float *scores = malloc(count * sizeof(float));
    void **ptrs = malloc(count * sizeof(void *));
    if (scores == NULL || ptrs == NULL) {
        /* fallback: no median if memory fails */
        stats.median = 0.0f;
        free(scores);
        free(ptrs);
        return stats;
    }

    for (int i = 0; i < count; i++) {
        scores[i] = dataset[i].score;
        ptrs[i] = &scores[i];
    }

    cmp_sort(ptrs, 0, count - 1, cmp1);

    if (count % 2 == 1) {
        int mid = count / 2;
        stats.median = *(float *)ptrs[mid];
    } else {
        int right_mid = count / 2;
        int left_mid = right_mid - 1;
        float a = *(float *)ptrs[left_mid];
        float b = *(float *)ptrs[right_mid];
        stats.median = (a + b) / 2.0f;
    }

    free(scores);
    free(ptrs);

    return stats;
}

int report_data(FILE *fp, RECORD *dataset, STATS stats) {
    if (fp == NULL || dataset == NULL) {
        return 0;
    }

    fprintf(fp, "Name                 Score   Grade\n");
    fprintf(fp, "-----------------------------------\n");

    int printed = 0;
    for (int i = 0; i < stats.count; i++) {
        GRADE g = grade(dataset[i].score);
        fprintf(fp, "%-20s %6.2f  %s\n", dataset[i].name, dataset[i].score, g.letter_grade);
        printed++;
    }

    fprintf(fp, "\n");
    fprintf(fp, "Count  : %d\n", stats.count);
    fprintf(fp, "Mean   : %.2f\n", stats.mean);
    fprintf(fp, "Stddev : %.2f\n", stats.stddev);
    fprintf(fp, "Median : %.2f\n", stats.median);

    return printed;
}
