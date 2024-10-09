#include <iostream>
#include <string>

using namespace std;

int main() {
    int age;
    string fitnessGoal;
    string dietaryRestriction;
    int availableTime;
    string healthCondition;
    float weight, height, bmi;
    string locationPreference;
    string workoutIntensity;
    float dailyCalories = 2000;
    float waterIntake = 1.5;

    cout << "Enter your age: ";
    cin >> age;

    cout << "What is your fitness goal? (build muscle / lose weight / maintain): ";
    cin.ignore();
    getline(cin, fitnessGoal);

    cout << "Do you have any dietary restrictions? (vegetarian / pescatarian / gluten-free / keto / none): ";
    getline(cin, dietaryRestriction);

    cout << "How many hours do you have available weekly for exercises? ";
    cin >> availableTime;

    cout << "Do you have any existing health conditions? (if none, type 'none'): ";
    cin.ignore();
    getline(cin, healthCondition);

    cout << "Enter your weight (in kg): ";
    cin >> weight;

    cout << "Enter your height (in meters): ";
    cin >> height;

    cout << "What is your preferred workout intensity? (low / medium / high): ";
    cin.ignore();
    getline(cin, workoutIntensity);

    cout << "Where do you prefer to work out? (gym / outdoor / home): ";
    getline(cin, locationPreference);

    bmi = weight / (height * height);

    if (age < 25) {
        dailyCalories += 300;
    }
    else if (age > 50) {
        dailyCalories -= 300;
    }

    if (workoutIntensity == "low") {
        waterIntake += 0.5;
        if (fitnessGoal == "build muscle") {
            dailyCalories -= 100;
        }
    }
    else if (workoutIntensity == "medium") {
        waterIntake += 1.0;
        if (fitnessGoal == "build muscle") {
            dailyCalories += 100;
        }
    }
    else if (workoutIntensity == "high") {
        waterIntake += 1.5;
        if (fitnessGoal == "build muscle") {
            dailyCalories += 200;
        }
    }

    string exerciseSuggestion;
    if (fitnessGoal == "lose weight") {
        if (bmi >= 25) {
            exerciseSuggestion = "Intense cardio and strength training are suggested.";
            dailyCalories -= 500;
        }
        else {
            exerciseSuggestion = "Moderate cardio and light weight training are suggested.";
            dailyCalories -= 250;
        }
    }
    else if (fitnessGoal == "build muscle") {
        if (availableTime > 7) {
            exerciseSuggestion = "Heavy weight training with minimal cardio is advised.";
            dailyCalories += 500;
        }
        else {
            exerciseSuggestion = "Moderate weight training with some cardio is recommended.";
            dailyCalories -= 250;
        }
    }
    else if (fitnessGoal == "maintain") {
        exerciseSuggestion = "A balanced mix of cardio and weight training is recommended.";
    }

    if (locationPreference == "gym") {
        exerciseSuggestion += " In the gym, focus on cardio machines and free weights.";
    }
    else if (locationPreference == "home") {
        exerciseSuggestion += " At home, try bodyweight exercises, yoga, and resistance bands.";
    }
    else if (locationPreference == "outdoor") {
        exerciseSuggestion += " Outdoors, focus on running, cycling, or hiking.";
    }

    cout << "\n--- Your Fitness Profile ---" << endl;
    cout << "Age: " << age << " years" << endl;
    cout << "Fitness Goal: " << fitnessGoal << endl;
    cout << "Dietary Restriction: " << dietaryRestriction << endl;
    cout << "Available Time for Exercises: " << availableTime << " hours/week" << endl;
    cout << "Health Condition: " << healthCondition << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "Height: " << height << " meters" << endl;
    cout << "Workout Location Preference: " << locationPreference << endl;

    cout << "\n--- BMI Results ---" << endl;
    cout << "Your BMI is: " << bmi << endl;
    if (bmi < 18) {
        cout << "You are underweight." << endl;
    }
    else if (bmi >= 18 && bmi <= 25) {
        cout << "You have a normal weight." << endl;
    }
    else if (bmi > 25 && bmi <= 30) {
        cout << "You are overweight." << endl;
    }
    else {
        cout << "You are obese." << endl;
    }

    cout << "\nYour daily calories should be: " << dailyCalories << " kcal" << endl;
    cout << "Your recommended exercises are: " << exerciseSuggestion << endl;
    cout << "Your recommended water intake is: " << waterIntake << " liters per day" << endl;
    if (healthCondition != "none") {
        cout << "\nNOTICE: Since you have a medical condition we highly suggest to consult a professional for medical advice." << endl;
    }

    return 0;
}
