#include <stdio.h>
#include <string.h>
#include <ctype.h>

// MODULE 1: DATA REPRESENTATION
struct Candidate {
    char name[50];
    char skills[100];
    int experience;
    int score;
};

// MODULE 2: EVALUATION LOGIC
int calculate_score(char skills[], int exp) {
    int score = 0;
    // Simple keyword matching (AI-lite logic)
    if (strstr(skills, "C")) score += 30;
    if (strstr(skills, "Python")) score += 30;
    if (strstr(skills, "Data Structures")) score += 20;
    
    // Experience threshold
    if (exp >= 3) score += 20;
    else if (exp >= 1) score += 10;
    
    return score;
}

int main() {
    struct Candidate c;
    FILE *fptr;

    // Input
    printf("Enter Name: ");
    scanf("%s", c.name);
    printf("Enter Skills: ");
    scanf(" %[^\n]s", c.skills); 
    printf("Enter Years of Experience: ");
    scanf("%d", &c.experience);

    c.score = calculate_score(c.skills, c.experience);

    // MODULE 3: STORAGE
    fptr = fopen("EvaluationReport.txt", "a");
    if(fptr == NULL) return 1;

    fprintf(fptr, "Candidate: %s | Score: %d\n", c.name, c.score);
    fclose(fptr);

    printf("\nAnalysis Complete. Score: %d%%\n", c.score);
    printf("Report saved to EvaluationReport.txt\n");

    return 0;
}