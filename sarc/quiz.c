#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 10

int main() {
    // Questions
    char *questions[TOTAL_QUESTIONS] = {
        "What is the capital of France?\n(a) Paris\n(b) London\n(c) Berlin\n",
        "Which language is used for system programming?\n(a) Python\n(b) C\n(c) HTML\n",
        "Which planet is known as the Red Planet?\n(a) Earth\n(b) Mars\n(c) Jupiter\n",
        "Which gas do plants release during photosynthesis?\n(a) Oxygen\n(b) Carbon Dioxide\n(c) Nitrogen\n",
        "Who wrote 'Romeo and Juliet'?\n(a) Charles Dickens\n(b) William Shakespeare\n(c) Mark Twain\n",
        "Which is the largest ocean on Earth?\n(a) Atlantic\n(b) Indian\n(c) Pacific\n",
        "What is the boiling point of water?\n(a) 100°C\n(b) 0°C\n(c) 50°C\n",
        "Which planet has rings?\n(a) Saturn\n(b) Venus\n(c) Mercury\n",
        "What is the currency of Japan?\n(a) Yen\n(b) Dollar\n(c) Euro\n",
        "Which is the smallest prime number?\n(a) 1\n(b) 2\n(c) 3\n"
    };

    // Correct answers
    char answers[TOTAL_QUESTIONS] = {'a','b','b','a','b','c','a','a','a','b'};

    int score = 0;
    char userAnswer;
    int asked[TOTAL_QUESTIONS] = {0};  // To keep track of asked questions
    int questionsAsked = 0;

    srand(time(0)); // Seed random number generator

    printf("Welcome to the Advanced Quiz Game!\n\n");

    while (questionsAsked < TOTAL_QUESTIONS) {
        int q = rand() % TOTAL_QUESTIONS;

        if (asked[q] == 0) { // Ask only if not already asked
            printf("Q%d: %s", questionsAsked + 1, questions[q]);
            printf("Enter your answer (a/b/c): ");
            scanf(" %c", &userAnswer);  // space before %c consumes newline

            // Convert to lowercase
            userAnswer = tolower(userAnswer);

            if (userAnswer == answers[q]) {
                printf("Correct!\n\n");
                score++;
            } else {
                printf("Wrong! The correct answer is '%c'.\n\n", answers[q]);
            }

            asked[q] = 1;  // Mark question as asked
            questionsAsked++;
        }
    }

    printf("Quiz Over! Your final score: %d/%d\n", score, TOTAL_QUESTIONS);

    
    if(score == TOTAL_QUESTIONS) {
        printf("Excellent! You got all answers right!\n");
    } else if(score >= TOTAL_QUESTIONS * 0.7) {
        printf("Great job! You scored above 70%%!\n");
    } else if(score >= TOTAL_QUESTIONS * 0.4) {
        printf("Not bad, but you can do better.\n");
    } else {
        printf("Better luck next time!\n");
    }

    return 0;
}

