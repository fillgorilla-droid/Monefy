//
// Created by User on 5/30/2026.
//

#ifndef UNTITLED3_FINANCE_SYSTEM_H
#define UNTITLED3_FINANCE_SYSTEM_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include "AydinString.h"
#include "Colors.h"

using namespace std;

enum Choices
{
    EXIT,
    ADD_INCOME,
    ADD_EXPENSE,
    SHOW_CATEGORIES,
    SHOW_BALANCE,
    DELETE_EXPENSE_CATEGORY,
    DELETE_INCOME_CATEGORY,
    CHANGE_EXPENSE_CATEGORY,
    CHANGE_INCOME_CATEGORY,
    CHANGE_INCOME_CATEGORY_FOR_MONEY,
    CHANGE_EXPENSE_CATEGORY_FOR_MONEY,
    ADD_EXPENSE_SUBCATEGORY,
    ADD_INCOME_SUBCATEGORY,
    DELETE_EXPENSE_SUBCATEGORY,
    DELETE_INCOME_SUBCATEGORY,
    CHANGE_EXPENSE_SUBCATEGORY,
    CHANGE_INCOME_SUBCATEGORY,
    SET_BUDGET_LIMITS,
    CHECK_BUDGET_LIMITS,
    SHOW_BUDGET,
    DELETE_BUDGET_LIMITS,
    CHANGE_BUDGET_LIMITS,
    ADD_REMINDER,
    DELETE_REMINDER,
    CHANGE_REMINDER_NAME,
    CHANGE_REMINDER_TEXT,
    SHOW_REMINDER,
    SHOW_STATISTICS,
    COLOR_CHOICE,
    TEXT_CHOICE,
    CLEAR_ALL
};

class FinanceSystem {
private:

    float* income;
    float* consumption;
    float* budgetLimits;

    MyString* budgetCategories;
    MyString* incomeCategories;
    MyString* consumptionCategories;
    MyString* Incomesubcategory;
    MyString* Consumptionsubcategory;
    MyString* reminderNames;
    MyString* reminderTexts;
    MyString* incomeDates;
    MyString* consumptionDates;

    unsigned int incomeCount;
    unsigned int consumptionCount;
    unsigned int budgetCount;
    unsigned int reminderCount;

public:

    FinanceSystem() {

        income = nullptr;
        consumption = nullptr;
        budgetLimits = nullptr;

        incomeCategories = nullptr;
        consumptionCategories = nullptr;
        Consumptionsubcategory = nullptr;
        Incomesubcategory = nullptr;

        reminderNames = nullptr;
        reminderTexts = nullptr;

        incomeDates = nullptr;
        consumptionDates = nullptr;

        reminderCount = 0;
        incomeCount = 0;
        consumptionCount = 0;
        budgetCount = 0;
    }

    void addIncome(float money,const MyString& category_name,const MyString& date)
    {
        if (money < 0) return;

        MyString* tempCategory = new MyString[incomeCount + 1];
        MyString* tempSubcategory = new MyString[incomeCount + 1];
        MyString* tempDates = new MyString[incomeCount + 1];
        float* tempMoney = new float[incomeCount + 1];

        for (int i = 0; i < incomeCount; i++)
        {
            tempCategory[i] = incomeCategories[i];
            tempSubcategory[i] = Incomesubcategory[i];
            tempMoney[i] = income[i];

            if (incomeDates != nullptr)
                tempDates[i] = incomeDates[i];
        }

        tempCategory[incomeCount] = category_name;
        tempSubcategory[incomeCount] = MyString("");
        tempMoney[incomeCount] = money;
        tempDates[incomeCount] = date;

        delete[] incomeCategories;
        delete[] Incomesubcategory;
        delete[] income;
        delete[] incomeDates;

        incomeCategories = tempCategory;
        Incomesubcategory = tempSubcategory;
        income = tempMoney;
        incomeDates = tempDates;

        incomeCount++;
    }

    void addIncomeSubcategory(float money, const MyString& category_name, const MyString& subcategory_name) {
        if (money < 0) return;

        for (int i = 0; i < incomeCount; i++)
        {
            if (incomeCategories[i] == category_name && Incomesubcategory[i] == MyString(""))
            {
                Incomesubcategory[i] = subcategory_name;
                income[i] = money;
                return;
            }
        }
    }


    void addConsumptionSubcategory(float money, const MyString& category_name, const MyString& subcategory_name)
    {
        if (money < 0) return;

        for (int i = 0; i < consumptionCount; i++)
        {
            if (consumptionCategories[i] == category_name && Consumptionsubcategory[i] == MyString(""))
            {
                Consumptionsubcategory[i] = subcategory_name;
                consumption[i] = money;
                return;
            }
        }
    }

    void addExpense(float money,const MyString& category_name,const MyString& date)
    {
        if (money < 0) return;

        checkBudget();

        MyString* tempCategory = new MyString[consumptionCount + 1];

        MyString* tempSubcategory = new MyString[consumptionCount + 1];

        MyString* tempDates = new MyString[consumptionCount + 1];

        float* tempMoney = new float[consumptionCount + 1];

        for (int i = 0; i < consumptionCount; i++)
        {
            tempCategory[i] = consumptionCategories[i];
            tempSubcategory[i] = Consumptionsubcategory[i];
            tempMoney[i] = consumption[i];
            tempDates[i] = consumptionDates[i];
        }

        tempCategory[consumptionCount] = category_name;
        tempSubcategory[consumptionCount] = "";
        tempMoney[consumptionCount] = money;
        tempDates[consumptionCount] = date;

        delete[] consumptionCategories;
        delete[] Consumptionsubcategory;
        delete[] consumption;
        delete[] consumptionDates;

        consumptionCategories = tempCategory;
        Consumptionsubcategory = tempSubcategory;
        consumption = tempMoney;
        consumptionDates = tempDates;

        consumptionCount++;
    }

    void deleteConsumptionSubcategory(const MyString& category_name,const MyString& subcategory_name)
    {
        for (int i = 0; i < consumptionCount; i++)
        {
            if (consumptionCategories[i] == category_name &&
                Consumptionsubcategory[i] == subcategory_name)
            {
                Consumptionsubcategory[i] = MyString("");
                return;
            }
        }
    }

    void changeConsumptionSubcategory(const MyString& category_name, const MyString& new_subcategory_name,const MyString& old_subcategory_name) {
        for (int i = 0; i < consumptionCount; i++)
        {
            if (consumptionCategories[i] == category_name && Consumptionsubcategory[i] == old_subcategory_name)
            {
                Consumptionsubcategory[i] = new_subcategory_name;
                return;
            }
        }
    }

    void changeIncomeSubcategory(const MyString& category_name,const MyString& new_subcategory_name,const MyString& old_subcategory_name) {
        for (int i = 0; i < incomeCount; i++) {
            if (incomeCategories[i] == category_name && Incomesubcategory[i] == old_subcategory_name) {
                Incomesubcategory[i] = new_subcategory_name;
                return;
            }
        }
    }


    void deleteIncomeCategory(const MyString& category) {

        if (incomeCount == 0) return;

        bool found = false;

        for (int i = 0; i < incomeCount; i++) {

            if (incomeCategories[i] == category) {
                found = true;
                break;
            }
        }

        if (!found) return;

        MyString* tempCategory = new MyString[incomeCount - 1];
        float* tempMoney = new float[incomeCount - 1];

        int j = 0;

        for (int i = 0; i < incomeCount; i++) {

            if (incomeCategories[i] != category) {

                tempCategory[j] = incomeCategories[i];
                tempMoney[j] = income[i];

                j++;
            }
        }

        delete[] incomeCategories;
        delete[] income;

        incomeCategories = tempCategory;
        income = tempMoney;

        incomeCount--;
    }

    void deleteIncomeSubcategory(const MyString& category_name, const MyString& subcategory_name) {
        for (int i = 0; i < incomeCount; i++)
        {
            if (incomeCategories[i] == category_name &&
                Incomesubcategory[i] == subcategory_name)
            {
                Incomesubcategory[i] = MyString("");
                return;
            }
        }
    }

    void deleteConsumptionCategory(const MyString& category)
    {
        if (consumptionCount == 0) return;

        bool found = false;

        for (int i = 0; i < consumptionCount; i++)
        {
            if (consumptionCategories[i] == category)
            {
                found = true;
                break;
            }
        }

        if (!found) return;

        MyString* tempCategory = new MyString[consumptionCount - 1];
        MyString* tempSubcategory = new MyString[consumptionCount - 1];
        float* tempMoney = new float[consumptionCount - 1];

        int j = 0;

        for (int i = 0; i < consumptionCount; i++)
        {
            if (consumptionCategories[i] != category)
            {
                tempCategory[j] = consumptionCategories[i];
                tempSubcategory[j] = Consumptionsubcategory[i];
                tempMoney[j] = consumption[i];

                j++;
            }
        }

        delete[] consumptionCategories;
        delete[] Consumptionsubcategory;
        delete[] consumption;

        consumptionCategories = tempCategory;
        Consumptionsubcategory = tempSubcategory;
        consumption = tempMoney;

        consumptionCount--;
    }


    void changeConsumptionCategory(const MyString& oldCategory, const MyString& newCategory) {

        for (int i = 0; i < consumptionCount; i++) {

            if (consumptionCategories[i] == oldCategory) {

                consumptionCategories[i] = newCategory;
                break;
            }
        }
    }

    void changeIncomeCategory(const MyString& oldCategory, const MyString& newCategory) {

        for (int i = 0; i < incomeCount; i++) {

            if (incomeCategories[i] == oldCategory) {

                incomeCategories[i] = newCategory;
                break;
            }
        }
    }

    void changeIncomeCategoryForMoney(float new_money, const MyString& category) {

        if (incomeCount == 0 || new_money < 0) return;

        for (int i = 0; i < incomeCount; i++) {

            if (incomeCategories[i] == category) {

                income[i] = new_money;
                break;
            }
        }
    }

    void changeConsumptionCategoryForMoney(float new_money, const MyString& category) {

        if (consumptionCount == 0 || new_money < 0) return;

        for (int i = 0; i < consumptionCount; i++) {

            if (consumptionCategories[i] == category) {

                consumption[i] = new_money;
                break;
            }
        }
    }

    void setBudgetLimit(const MyString& category, float limit)
    {
        if (limit < 0) return;

        if (budgetCount == 0)
        {
            budgetCategories = new MyString[1];
            budgetLimits = new float[1];

            budgetCategories[0] = category;
            budgetLimits[0] = limit;

            budgetCount = 1;
            return;
        }

        for (int i = 0; i < budgetCount; i++)
        {
            if (budgetCategories[i] == category)
            {
                budgetLimits[i] = limit;
                return;
            }
        }

        MyString* tempCategories = new MyString[budgetCount + 1];
        float* tempLimits = new float[budgetCount + 1];

        for (int i = 0; i < budgetCount; i++)
        {
            tempCategories[i] = budgetCategories[i];
            tempLimits[i] = budgetLimits[i];
        }

        tempCategories[budgetCount] = category;
        tempLimits[budgetCount] = limit;

        delete[] budgetCategories;
        delete[] budgetLimits;

        budgetCategories = tempCategories;
        budgetLimits = tempLimits;

        budgetCount++;
    }

    void deleteBudgetLimit(const MyString& category)
    {
        if (budgetCount == 0) return;

        bool found = false;

        for (int i = 0; i < budgetCount; i++)
        {
            if (budgetCategories[i] == category)
            {
                found = true;
                break;
            }
        }

        if (!found) return;

        if (budgetCount == 1)
        {
            delete[] budgetCategories;
            delete[] budgetLimits;

            budgetCategories = nullptr;
            budgetLimits = nullptr;

            budgetCount = 0;
            return;
        }

        MyString* tempCategories = new MyString[budgetCount - 1];
        float* tempLimits = new float[budgetCount - 1];

        int j = 0;

        for (int i = 0; i < budgetCount; i++)
        {
            if (budgetCategories[i] != category)
            {
                tempCategories[j] = budgetCategories[i];
                tempLimits[j] = budgetLimits[i];
                j++;
            }
        }

        delete[] budgetCategories;
        delete[] budgetLimits;

        budgetCategories = tempCategories;
        budgetLimits = tempLimits;

        budgetCount--;
    }

    void changeBudgetLimit(const MyString& category,float limit) {
        if (budgetCount == 0) return;
        bool found = false;
        for (int i = 0; i < budgetCount; i++) {
            if (budgetCategories[i] == category) {
                found = true;
                break;
            }
        }
        if (!found) return;

        for (int i = 0; i < budgetCount; i++) {
            if (budgetCategories[i] == category) {
                budgetLimits[i] = limit;
                break;
            }
        }
    }

    void checkBudget() const
    {
        if (budgetCount == 0 || budgetLimits == nullptr || budgetCategories == nullptr)
            return;

        for (int i = 0; i < budgetCount; i++)
        {
            float spent = 0;

            for (int j = 0; j < consumptionCount; j++)
            {
                if (consumptionCategories[j] == budgetCategories[i])
                {
                    spent += consumption[j];
                }
            }

            cout << budgetCategories[i]
                 << " : "
                 << spent
                 << " / "
                 << budgetLimits[i];

            if (spent > budgetLimits[i])
            {
                cout << "\nLIMIT EXCEEDED";
            }

            cout << '\n';
        }
    }

    void addReminder(const MyString& name, const MyString& text)
    {
        MyString* tempNames = new MyString[reminderCount + 1];
        MyString* tempTexts = new MyString[reminderCount + 1];

        for (int i = 0; i < reminderCount; i++)
        {
            tempNames[i] = reminderNames[i];
            tempTexts[i] = reminderTexts[i];
        }

        tempNames[reminderCount] = name;
        tempTexts[reminderCount] = text;

        delete[] reminderNames;
        delete[] reminderTexts;

        reminderNames = tempNames;
        reminderTexts = tempTexts;

        reminderCount++;
    }

    void deleteReminder(const MyString& name)
    {
        if (reminderCount == 0) return;

        bool found = false;

        for (int i = 0; i < reminderCount; i++)
        {
            if (reminderNames[i] == name)
            {
                found = true;
                break;
            }
        }

        if (!found) return;

        if (reminderCount == 1)
        {
            delete[] reminderNames;
            delete[] reminderTexts;

            reminderNames = nullptr;
            reminderTexts = nullptr;

            reminderCount = 0;
            return;
        }

        MyString* tempNames = new MyString[reminderCount - 1];
        MyString* tempTexts = new MyString[reminderCount - 1];

        int j = 0;

        for (int i = 0; i < reminderCount; i++)
        {
            if (reminderNames[i] != name)
            {
                tempNames[j] = reminderNames[i];
                tempTexts[j] = reminderTexts[i];
                j++;
            }
        }

        delete[] reminderNames;
        delete[] reminderTexts;

        reminderNames = tempNames;
        reminderTexts = tempTexts;

        reminderCount--;
    }
    void changeReminderText(const MyString& name,const MyString& newText)
    {
        if (reminderCount == 0) return;

        for (int i = 0; i < reminderCount; i++)
        {
            if (reminderNames[i] == name)
            {
                reminderTexts[i] = newText;
                return;
            }
        }
    }

    void changeReminderName(const MyString& oldName,const MyString& newName)
    {
        if (reminderCount == 0) return;

        for (int i = 0; i < reminderCount; i++)
        {
            if (reminderNames[i] == oldName)
            {
                reminderNames[i] = newName;
                return;
            }
        }
    }

    void showReminders() const {

        for (int i = 0; i < reminderCount; i++) {
            if (reminderCount <= 0) {
                cout << "\nNo Reminder\n";
            }
            else {
                cout << reminderNames[i] << ": " << reminderTexts[i] << '\n';
            }
        }
    }

    void showIncomeCategories() const {
        for (int i = 0; i < incomeCount; i++) {
            if (Incomesubcategory[i]) {
                cout << incomeCategories[i]
                    << " -> "
                        << Incomesubcategory[i]
                        << " : "
                            << income[i]
                            << '\n';
            }
            else {
                cout << incomeCategories[i] << " : " << income[i] << '\n';
            }
        }
    }

    void showExpenseCategories() const {

        for (int i = 0; i < consumptionCount; i++) {
            if (Consumptionsubcategory[i]) {
                cout << consumptionCategories[i]
                    << " -> "
                        << Consumptionsubcategory[i]
                        << " : "
                            << consumption[i]
                            << '\n';
            }
            else {
                cout << consumptionCategories[i] << " : " << consumption[i] << '\n';
            }
        }
    }

    void showStatistics(const MyString& from,const MyString& to) const
{
    float totalIncome = 0;
    float totalExpense = 0;

    for (int i = 0; i < incomeCount; i++)
    {
        if (incomeDates[i] >= from && incomeDates[i] <= to)
        {
            totalIncome += income[i];
        }
    }

    for (int i = 0; i < consumptionCount; i++)
    {
        if (consumptionDates[i] >= from &&consumptionDates[i] <= to)
        {
            totalExpense += consumption[i];
        }
    }

    float balance = totalIncome - totalExpense;

    cout << "\n===== STATISTICS =====\n";

    cout << "Period: " << from << " -> " << to << '\n';

    cout << "Total income: " << totalIncome << '\n';

    cout << "Total expense: " << totalExpense << '\n';

    cout << "Balance: " << balance << "\n\n";

    if (totalExpense <= 0)
    {
        cout << "No expenses for this period\n";
        return;
    }

    cout << "Expense percentages:\n";

    for (int i = 0; i < consumptionCount; i++)
    {
        if (consumptionDates[i] >= from &&consumptionDates[i] <= to)
        {
            bool alreadyShown = false;

            for (int j = 0; j < i; j++)
            {
                if (consumptionCategories[i] ==consumptionCategories[j])
                {
                    alreadyShown = true;
                    break;
                }
            }

            if (alreadyShown)
                continue;

            float categoryTotal = 0;

            for (int j = 0; j < consumptionCount; j++)
            {
                if (consumptionCategories[j] ==
                    consumptionCategories[i] &&
                    consumptionDates[j] >= from &&
                    consumptionDates[j] <= to)
                {
                    categoryTotal += consumption[j];
                }
            }

            float percent = (categoryTotal / totalExpense) * 100;

            cout << consumptionCategories[i]
                 << " -> "
                 << percent
                 << "%\n";
        }
    }
}

    void showCategories() const {

        cout << "\nINCOME CATEGORIES:\n\n";
        showIncomeCategories();

        cout << "\nEXPENSE CATEGORIES:\n\n";
        showExpenseCategories();

        cout << '\n';
    }

    void showBalance() const {

        float resultIncome = 0;
        float resultExpense = 0;

        for (int i = 0; i < incomeCount; i++) {
            resultIncome += income[i];
        }

        for (int i = 0; i < consumptionCount; i++) {
            resultExpense += consumption[i];
        }

        if (resultIncome - resultExpense < 0) {
            cout << "Balance: " << 0 << "\n\n";
        }
        else {
            cout << "Balance: " << resultIncome - resultExpense << "\n\n";
        }
    }

    void showBudgetLimits() const {
        if (budgetCount == 0 || budgetLimits == nullptr) {
            cout << "No budget set\n";
            return;
        }

        float resultBudgetLimit = 0;

        for (int i = 0; i < budgetCount; i++) {
            resultBudgetLimit += budgetLimits[i];
        }

        cout << "Your Limit: " << resultBudgetLimit << '\n';
    }

    void SaveToFile() const
    {
        ofstream file("finances.bin", ios::binary);

        if (!file)
            return;

        file.write((char*)&incomeCount, sizeof(incomeCount));

        for (int i = 0; i < incomeCount; i++)
        {
            incomeCategories[i].Write(file);
            Incomesubcategory[i].Write(file);
            incomeDates[i].Write(file);

            file.write((char*)&income[i], sizeof(float));
        }

        file.write((char*)&consumptionCount, sizeof(consumptionCount));

        for (int i = 0; i < consumptionCount; i++)
        {
            consumptionCategories[i].Write(file);
            Consumptionsubcategory[i].Write(file);
            consumptionDates[i].Write(file);

            file.write((char*)&consumption[i], sizeof(float));
        }

        file.write((char*)&budgetCount, sizeof(budgetCount));

        for (int i = 0; i < budgetCount; i++)
        {
            budgetCategories[i].Write(file);

            file.write((char*)&budgetLimits[i],sizeof(float));
        }

        file.write((char*)&reminderCount,sizeof(reminderCount));

        for (int i = 0; i < reminderCount; i++)
        {
            reminderNames[i].Write(file);
            reminderTexts[i].Write(file);
        }

        file.close();
    }

    void LoadFromFile()
    {
        ifstream file("finances.bin", ios::binary);

        if (!file)
            return;

        file.read((char*)&incomeCount, sizeof(incomeCount));

        if (incomeCount)
        {
            incomeCategories = new MyString[incomeCount];
            Incomesubcategory = new MyString[incomeCount];
            incomeDates = new MyString[incomeCount];
            income = new float[incomeCount];

            for (int i = 0; i < incomeCount; i++)
            {
                incomeCategories[i].Read(file);
                Incomesubcategory[i].Read(file);
                incomeDates[i].Read(file);

                file.read((char*)&income[i], sizeof(float));
            }
        }

        file.read((char*)&consumptionCount,sizeof(consumptionCount));

        if (consumptionCount)
        {
            consumptionCategories = new MyString[consumptionCount];

            Consumptionsubcategory = new MyString[consumptionCount];

            consumptionDates = new MyString[consumptionCount];

            consumption = new float[consumptionCount];

            for (int i = 0; i < consumptionCount; i++)
            {
                consumptionCategories[i].Read(file);
                Consumptionsubcategory[i].Read(file);
                consumptionDates[i].Read(file);

                file.read((char*)&consumption[i],
                    sizeof(float));
            }
        }

        file.read((char*)&budgetCount,sizeof(budgetCount));

        if (budgetCount)
        {
            budgetCategories = new MyString[budgetCount];

            budgetLimits = new float[budgetCount];

            for (int i = 0; i < budgetCount; i++)
            {
                budgetCategories[i].Read(file);

                file.read((char*)&budgetLimits[i],sizeof(float));
            }
        }

        file.read((char*)&reminderCount,sizeof(reminderCount));

        if (reminderCount)
        {
            reminderNames = new MyString[reminderCount];

            reminderTexts = new MyString[reminderCount];

            for (int i = 0; i < reminderCount; i++)
            {
                reminderNames[i].Read(file);
                reminderTexts[i].Read(file);
            }
        }

        file.close();
    }


    ~FinanceSystem() {

        delete[] incomeCategories;
        delete[] consumptionCategories;

        delete[] income;
        delete[] consumption;

        delete[] Consumptionsubcategory;
        delete[] Incomesubcategory;

        delete[] reminderNames;
        delete[] reminderTexts;

        delete[] budgetLimits;

        delete[] budgetCategories;

        delete[] incomeDates;
        delete[] consumptionDates;

        budgetCount = 0;
        incomeCount = 0;
        consumptionCount = 0;
        reminderCount = 0;
    }
};

inline bool isValidDate(const MyString& date)
{
    if (date.lenght() != 10)
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return false;
        }
        else
        {
            if (date[i] < '0' || date[i] > '9')
                return false;
        }
    }

    return true;
}

#endif //UNTITLED3_FINANCE_SYSTEM_H
