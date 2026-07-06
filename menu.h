//
// Created by User on 5/30/2026.
//

#ifndef UNTITLED3_MENU_H
#define UNTITLED3_MENU_H

#include "finance_system.h"

void menu()
{
    FinanceSystem system;

    unsigned short choice = 0;
    system.LoadFromFile();

    MyString TEXT = ITALIC;
    MyString COLOR = YELLOW;

    while (true)
{
    try
    {
        cout << TEXT;
        cout << COLOR;


cout <<
"\n\n"
"    +====================================================+\n"
"    |                 FINANCE SYSTEM MENU                |\n"
"    +====================================================+\n"
"    |                                                    |\n"
"    |  [ INCOME / EXPENSE ]                              |\n"
"    |  1.  Add Income                                    |\n"
"    |  2.  Add Expense                                   |\n"
"    |  3.  Show Categories                               |\n"
"    |  4.  Show Balance                                  |\n"
"    |                                                    |\n"
"    +====================================================+\n"
"    |  [ CATEGORY SETTINGS ]                             |\n"
"    |  5.  Delete Expense Category                       |\n"
"    |  6.  Delete Income Category                        |\n"
"    |  7.  Change Expense Category                       |\n"
"    |  8.  Change Income Category                        |\n"
"    |  9.  Change Income Money                           |\n"
"    | 10.  Change Expense Money                          |\n"
"    |                                                    |\n"
"    +====================================================+\n"
"    |  [ SUBCATEGORIES ]                                 |\n"
"    | 11. Add Expense Subcategory                        |\n"
"    | 12. Add Income Subcategory                         |\n"
"    | 13. Delete Expense Subcategory                     |\n"
"    | 14. Delete Income Subcategory                      |\n"
"    | 15. Change Expense Subcategory                     |\n"
"    | 16. Change Income Subcategory                      |\n"
"    |                                                    |\n"
"    +====================================================+\n"
"    |  [ BUDGET ]                                        |\n"
"    | 17. Set Budget Limits                              |\n"
"    | 18. Check Budget Limits                            |\n"
"    | 19. Show Budget Limits                             |\n"
"    | 20. Delete Budget Limits                           |\n"
"    | 21. Change Budget Limits                           |\n"
"    |                                                    |\n"
"    +====================================================+\n"
"    |  [ REMINDERS ]                                     |\n"
"    | 22. Add Reminder                                   |\n"
"    | 23. Delete Reminder                                |\n"
"    | 24. Change Reminder Name                           |\n"
"    | 25. Change Reminder Text                           |\n"
"    | 26. Show Reminders                                 |\n"
"    |                                                    |\n"
"    +====================================================+\n"
"    |  [ ANALYTICS ]                                     |\n"
"    | 27. Show Statistics                                |\n"
"    |                                                    |\n"
"    +====================================================+\n"
"    |  [ CUSTOMIZATION ]                                 |\n"
"    | 28. Change Color                                   |\n"
"    | 29. Change Text Style                              |\n"
"    |                                                    |\n"
"    +====================================================+\n"
"    | 30. Clear All                                      |\n"
"    |  0. Exit                                           |\n"
"    |                                                    |\n"
"    +====================================================+\n\n";

        cout << "Enter your choice -> ";
        cin >> choice;

        if (cin.fail())
        {
            throw invalid_argument("Invalid input");
        }

        switch (choice)
        {
        case EXIT:
        {
            cout << "\nGoodbye!\n";
            return;
        }

        case ADD_INCOME:
        {
            float money = 0;
            MyString category;
            MyString date;

            cout << "\n========== ADD INCOME ==========\n";

            cout << "Enter category -> ";
            cin >> category;

            cout << "Enter money -> ";
            cin >> money;

            cout << "Enter date (YYYY-MM-DD) -> ";
            cin >> date;

            if (!isValidDate(date))
            {
                cout << "\nInvalid date format!\n";
                break;
            }

            system.addIncome(money, category, date);
            system.SaveToFile();

            cout << "\nIncome added successfully!\n";
            break;
        }

        case ADD_EXPENSE:
        {
            float money = 0;
            MyString category;
            MyString date;

            cout << "\n========== ADD EXPENSE ==========\n";

            cout << "Enter category -> ";
            cin >> category;

            cout << "Enter money -> ";
            cin >> money;

            cout << "Enter date (YYYY-MM-DD) -> ";
            cin >> date;

            if (!isValidDate(date))
            {
                cout << "\nInvalid date format!\n";
                break;
            }

            system.addExpense(money, category, date);
            system.SaveToFile();

            cout << "\nExpense added successfully!\n";
            break;
        }

        case SHOW_CATEGORIES:
        {
            cout << "\n========== ALL CATEGORIES ==========\n";
            system.showCategories();
            break;
        }

        case SHOW_BALANCE:
        {
            cout << "\n========== BALANCE ==========\n";
            system.showBalance();
            break;
        }

        case DELETE_EXPENSE_CATEGORY:
        {
            MyString category;

            cout << "\n========== DELETE EXPENSE CATEGORY ==========\n";

            cout << "Enter category -> ";
            cin >> category;

            system.deleteConsumptionCategory(category);
            system.SaveToFile();

            cout << "\nCategory deleted!\n";
            break;
        }

        case DELETE_INCOME_CATEGORY:
        {
            MyString category;

            cout << "\n========== DELETE INCOME CATEGORY ==========\n";

            cout << "Enter category -> ";
            cin >> category;

            system.deleteIncomeCategory(category);
            system.SaveToFile();

            cout << "\nCategory deleted!\n";
            break;
        }

        case CHANGE_EXPENSE_CATEGORY:
        {
            MyString old_category;
            MyString new_category;

            cout << "\n========== CHANGE EXPENSE CATEGORY ==========\n";

            cout << "Old category -> ";
            cin >> old_category;

            cout << "New category -> ";
            cin >> new_category;

            system.changeConsumptionCategory(old_category, new_category);
            system.SaveToFile();

            cout << "\nCategory changed!\n";
            break;
        }

        case CHANGE_INCOME_CATEGORY:
        {
            MyString old_category;
            MyString new_category;

            cout << "\n========== CHANGE INCOME CATEGORY ==========\n";

            cout << "Old category -> ";
            cin >> old_category;

            cout << "New category -> ";
            cin >> new_category;

            system.changeIncomeCategory(old_category, new_category);
            system.SaveToFile();

            cout << "\nCategory changed!\n";
            break;
        }

        case CHANGE_INCOME_CATEGORY_FOR_MONEY:
        {
            MyString category;
            float money = 0;

            cout << "\n========== CHANGE INCOME MONEY ==========\n";

            cout << "Category -> ";
            cin >> category;

            cout << "New money -> ";
            cin >> money;

            system.changeIncomeCategoryForMoney(money, category);
            system.SaveToFile();

            cout << "\nMoney updated!\n";
            break;
        }

        case CHANGE_EXPENSE_CATEGORY_FOR_MONEY:
        {
            MyString category;
            float money = 0;

            cout << "\n========== CHANGE EXPENSE MONEY ==========\n";

            cout << "Category -> ";
            cin >> category;

            cout << "New money -> ";
            cin >> money;

            system.changeConsumptionCategoryForMoney(money, category);
            system.SaveToFile();

            cout << "\nMoney updated!\n";
            break;
        }

        case ADD_EXPENSE_SUBCATEGORY:
        {
            float money = 0;
            MyString category;
            MyString subcategory;

            cout << "\n========== ADD EXPENSE SUBCATEGORY ==========\n";

            cout << "Money -> ";
            cin >> money;

            cout << "Category -> ";
            cin >> category;

            cout << "Subcategory -> ";
            cin >> subcategory;

            system.addConsumptionSubcategory(money, category, subcategory);
            system.SaveToFile();

            cout << "\nSubcategory added!\n";
            break;
        }

        case ADD_INCOME_SUBCATEGORY:
        {
            float money = 0;
            MyString category;
            MyString subcategory;

            cout << "\n========== ADD INCOME SUBCATEGORY ==========\n";

            cout << "Money -> ";
            cin >> money;

            cout << "Category -> ";
            cin >> category;

            cout << "Subcategory -> ";
            cin >> subcategory;

            system.addIncomeSubcategory(money, category, subcategory);
            system.SaveToFile();

            cout << "\nSubcategory added!\n";
            break;
        }

        case DELETE_EXPENSE_SUBCATEGORY:
        {
            MyString category;
            MyString subcategory;

            cout << "\n========== DELETE EXPENSE SUBCATEGORY ==========\n";

            cout << "Category -> ";
            cin >> category;

            cout << "Subcategory -> ";
            cin >> subcategory;

            system.deleteConsumptionSubcategory(category, subcategory);
            system.SaveToFile();

            cout << "\nSubcategory deleted!\n";
            break;
        }

        case DELETE_INCOME_SUBCATEGORY:
        {
            MyString category;
            MyString subcategory;

            cout << "\n========== DELETE INCOME SUBCATEGORY ==========\n";

            cout << "Category -> ";
            cin >> category;

            cout << "Subcategory -> ";
            cin >> subcategory;

            system.deleteIncomeSubcategory(category, subcategory);
            system.SaveToFile();

            cout << "\nSubcategory deleted!\n";
            break;
        }

        case CHANGE_EXPENSE_SUBCATEGORY:
        {
            MyString category;
            MyString old_subcategory;
            MyString new_subcategory;

            cout << "\n========== CHANGE EXPENSE SUBCATEGORY ==========\n";

            cout << "Category -> ";
            cin >> category;

            cout << "Old subcategory -> ";
            cin >> old_subcategory;

            cout << "New subcategory -> ";
            cin >> new_subcategory;

            system.changeConsumptionSubcategory(category, new_subcategory, old_subcategory);
            system.SaveToFile();

            cout << "\nSubcategory changed!\n";
            break;
        }

        case CHANGE_INCOME_SUBCATEGORY:
        {
            MyString category;
            MyString old_subcategory;
            MyString new_subcategory;

            cout << "\n========== CHANGE INCOME SUBCATEGORY ==========\n";

            cout << "Category -> ";
            cin >> category;

            cout << "Old subcategory -> ";
            cin >> old_subcategory;

            cout << "New subcategory -> ";
            cin >> new_subcategory;

            system.changeIncomeSubcategory(category, new_subcategory, old_subcategory);
            system.SaveToFile();

            cout << "\nSubcategory changed!\n";
            break;
        }

        case SET_BUDGET_LIMITS:
        {
            MyString category;
            float limit = 0;

            cout << "\n========== SET BUDGET LIMIT ==========\n";

            cout << "Category -> ";
            cin >> category;

            cout << "Limit -> ";
            cin >> limit;

            system.setBudgetLimit(category, limit);
            system.SaveToFile();

            cout << "\nBudget limit set!\n";
            break;
        }

        case CHECK_BUDGET_LIMITS:
        {
            cout << "\n========== BUDGET CHECK ==========\n";
            system.checkBudget();
            break;
        }

        case SHOW_BUDGET:
        {
            cout << "\n========== BUDGET LIMITS ==========\n";
            system.showBudgetLimits();
            break;
        }

        case DELETE_BUDGET_LIMITS:
        {
            MyString category;

            cout << "\n========== DELETE BUDGET LIMIT ==========\n";

            cout << "Category -> ";
            cin >> category;

            system.deleteBudgetLimit(category);
            system.SaveToFile();

            cout << "\nBudget limit deleted!\n";
            break;
        }

        case CHANGE_BUDGET_LIMITS:
        {
            MyString category;
            float limit = 0;

            cout << "\n========== CHANGE BUDGET LIMIT ==========\n";

            cout << "Category -> ";
            cin >> category;

            cout << "New limit -> ";
            cin >> limit;

            system.changeBudgetLimit(category, limit);
            system.SaveToFile();

            cout << "\nBudget limit changed!\n";
            break;
        }

        case ADD_REMINDER:
        {
            char buffer[100];
            MyString name;
            MyString text;

            cout << "\n========== ADD REMINDER ==========\n";

            cout << "Reminder text -> ";

            cin.ignore();
            cin.getline(buffer, 100);

            cout << "Reminder name -> ";
            cin >> name;

            text = buffer;

            system.addReminder(name, text);
            system.SaveToFile();

            cout << "\nReminder added!\n";
            break;
        }

        case DELETE_REMINDER:
        {
            MyString name;

            cout << "\n========== DELETE REMINDER ==========\n";

            cout << "Reminder name -> ";
            cin >> name;

            system.deleteReminder(name);
            system.SaveToFile();

            cout << "\nReminder deleted!\n";
            break;
        }

        case CHANGE_REMINDER_NAME:
        {
            MyString old_reminder;
            MyString new_reminder;

            cout << "\n========== CHANGE REMINDER NAME ==========\n";

            cout << "Old name -> ";
            cin >> old_reminder;

            cout << "New name -> ";
            cin >> new_reminder;

            system.changeReminderName(old_reminder, new_reminder);
            system.SaveToFile();

            cout << "\nReminder name changed!\n";
            break;
        }

        case CHANGE_REMINDER_TEXT:
        {
            MyString name;
            MyString text;
            char buffer[100];

            cout << "\n========== CHANGE REMINDER TEXT ==========\n";

            cout << "Reminder name -> ";
            cin >> name;

            cout << "New text -> ";

            cin.ignore();
            cin.getline(buffer, 100);

            text = buffer;

            system.changeReminderText(name, text);
            system.SaveToFile();

            cout << "\nReminder text changed!\n";
            break;
        }

        case SHOW_REMINDER:
        {
            cout << "\n========== REMINDERS ==========\n";
            system.showReminders();
            break;
        }

        case SHOW_STATISTICS:
        {
            MyString from;
            MyString to;

            cout << "\n========== STATISTICS ==========\n";

            cout << "From (YYYY-MM-DD) -> ";
            cin >> from;

            cout << "To (YYYY-MM-DD) -> ";
            cin >> to;

            if (!isValidDate(from) || !isValidDate(to))
            {
                cout << "\nInvalid date format!\n";
                break;
            }

            system.showStatistics(from, to);
            break;
        }

        case CLEAR_ALL: {
            system.~FinanceSystem();

            break;
        }

        case COLOR_CHOICE:
        {
            unsigned short choice_for_color = 0;

            cout << "\n========== COLOR SETTINGS ==========\n";

            color_table();

            cout << "Choose color -> ";
            cin >> choice_for_color;

            switch (choice_for_color)
            {
            case _BLACK: COLOR = BLACK; break;
            case _RED: COLOR = RED; break;
            case _GREEN: COLOR = GREEN; break;
            case _YELLOW: COLOR = YELLOW; break;
            case _BLUE: COLOR = BLUE; break;
            case _MAGENTA: COLOR = MAGENTA; break;
            case _CYAN: COLOR = CYAN; break;
            case _WHITE: COLOR = WHITE; break;

            default:
                cout << "\nWrong color!\n";
                break;
            }

            break;
        }

        case TEXT_CHOICE:
        {
            unsigned short choice_for_text = 0;

            cout << "\n========== TEXT STYLE SETTINGS ==========\n";

            text_style();

            cout << "Choose style -> ";
            cin >> choice_for_text;

            switch (choice_for_text)
            {
            case Text::_BOLD: TEXT = BOLD; break;
            case Text::_DIM: TEXT = DIM; break;
            case Text::_ITALIC: TEXT = ITALIC; break;
            case Text::_UNDERLINE: TEXT = UNDERLINE; break;
            case Text::_BLINK: TEXT = BLINK; break;
            case Text::_REVERSE: TEXT = REVERSE; break;
            case Text::_HIDDEN: TEXT = HIDDEN; break;

            default:
                cout << "\nWrong style!\n";
                break;
            }

            break;
        }

        default:
            cout << "\nWrong choice!\n";
        }

        cout << "\nPress ENTER to continue...";
        cin.ignore();
        cin.get();
    }
    catch (const char* error)
    {
        cout << "\nERROR: " << error << '\n';

        cin.clear();
        cin.ignore(1000, '\n');
    }
    catch (const invalid_argument& e)
    {
        cout << "\nERROR: " << e.what() << '\n';

        cin.clear();
        cin.ignore(1000, '\n');
    }
}

    return;
}


#endif //UNTITLED3_MENU_H
