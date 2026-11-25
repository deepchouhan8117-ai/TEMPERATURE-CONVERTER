/*
 * Temperature Converter
 * Skills used: Functions, Arithmetic Operators
 * Converts between Celsius, Fahrenheit and Kelvin
 */

#include <stdio.h>

/* ---------- Conversion functions ---------- */
float celsiusToFahrenheit(float c) { return (c * 9.0f / 5.0f) + 32.0f; }
float celsiusToKelvin(float c)     { return c + 273.15f; }

float fahrenheitToCelsius(float f) { return (f - 32.0f) * 5.0f / 9.0f; }
float fahrenheitToKelvin(float f)  { return (f - 32.0f) * 5.0f / 9.0f + 273.15f; }

float kelvinToCelsius(float k)     { return k - 273.15f; }
float kelvinToFahrenheit(float k)  { return (k - 273.15f) * 9.0f / 5.0f + 32.0f; }

/* ---------- Menu ---------- */
void displayMenu(void) {
    printf("\n===== TEMPERATURE CONVERTER =====\n");
    printf("1. Celsius    to Fahrenheit\n");
    printf("2. Celsius    to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin     to Celsius\n");
    printf("6. Kelvin     to Fahrenheit\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main(void) {
    int choice;
    float temp, result;

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {      /* handles letters typed by mistake */
            printf("Invalid input! Enter a number.\n");
            while (getchar() != '\n');        /* clear input buffer */
            continue;
        }

        if (choice == 7) {
            printf("Thank you for using the converter!\n");
            break;
        }
        if (choice < 1 || choice > 6) {
            printf("Invalid choice! Choose between 1 and 7.\n");
            continue;
        }

        printf("Enter temperature: ");
        scanf("%f", &temp);

        /* Absolute zero check: Kelvin cannot be negative */
        if ((choice == 5 || choice == 6) && temp < 0) {
            printf("Kelvin cannot be below 0 (absolute zero)!\n");
            continue;
        }

        switch (choice) {
            case 1: result = celsiusToFahrenheit(temp);
                    printf("%.2f C = %.2f F\n", temp, result); break;
            case 2: result = celsiusToKelvin(temp);
                    printf("%.2f C = %.2f K\n", temp, result); break;
            case 3: result = fahrenheitToCelsius(temp);
                    printf("%.2f F = %.2f C\n", temp, result); break;
            case 4: result = fahrenheitToKelvin(temp);
                    printf("%.2f F = %.2f K\n", temp, result); break;
            case 5: result = kelvinToCelsius(temp);
                    printf("%.2f K = %.2f C\n", temp, result); break;
            case 6: result = kelvinToFahrenheit(temp);
                    printf("%.2f K = %.2f F\n", temp, result); break;
        }
    } while (choice != 7);

    return 0;
}