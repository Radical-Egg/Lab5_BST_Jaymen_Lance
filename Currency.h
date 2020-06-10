/*
	Lab 01A: Classes and Inheritance

	Lance Carrido

	This lab demonstrates classes and inheritance through a currency base class
	and five derived currency classes, as well as polymorphism through operator
	overloading.

	Assumption: Negative values on currencies are allowed.
*/

#ifndef CURRENCY_H_
#define CURRENCY_H_

#include <string>
#include <iostream>

class Currency
{
protected:
	int noteValue;
	int coinValue;

	/*
		void roundCoinToNote();

		Carries over to the note value if the coin value
		is greater than or equal 100 or less than 0

		Pre		None.
		Post	Coin value is between 0 inclusive and 100 exclusive
				For every 100/-100 coin value, 1/-1 is added to Note value.
		Return	None.
	*/

	void roundCoinToNote();

public:
	Currency(int noteValue = 0, int coinValue = 0) : noteValue(noteValue), coinValue(coinValue)
	{
		roundCoinToNote();
	}

	virtual ~Currency() {}

	/*
		int getNoteValue() const;

		Gets the current note value.

		Pre		None.
		Post	None.
		Return	The current note value of the currency.
	*/

	int getNoteValue() const;

	/*
		void setNoteValue(int noteValue);

		Sets the note value to a specified value.

		Pre		int noteValue - the value to replace the note value.
		Post	The note value is replaced by the specified value.
		Return	None.
	*/

	void setNoteValue(int noteValue);

	/*
		int getCoinValue() const;

		Gets the current coin value.

		Pre		None.
		Post	None.
		Return	The current coin value of the currency.
	*/

	int getCoinValue() const;

	/*
		void setCoinValue(int coinValue);

		Sets the coin value to a specified value.

		Pre		int coinValue - the value to replace the coin value.
		Post	The coin value is replaced by the specified value.
		Return	None.
	*/

	void setCoinValue(int coinValue);

	/*
		std::string getNoteName() const;

		Gets the name of the currency's note.

		Pre		None.
		Post	None.
		Return	The name of the currency's note.
	*/

	virtual std::string getNoteName() const;

	/*
		std::string getCoinName() const;

		Gets the name of the currency's coin.

		Pre		None.
		Post	None.
		Return	The name of the currency's coin.
	*/

	virtual std::string getCoinName() const;

	/*
		bool isMatchingCurrency(Currency const& currency) const;

		Checks if two currency objects are the same type

		Pre		Currency const &currency - The currency object to compare with
		Post	None
		Return	True - Both currencies are the same type.
				False - Both currencies are not the same type.
	*/

	bool isMatchingCurrency(Currency const &currency) const;

	/*
		Currency operator + (Currency const &currencyR);

		Adds the value of two matching currencies via + operator

		Pre		Currency const &currencyR - The right operand
		Post	Both currencies' value are added together.
				Overflowing coin values are carried over.
				Throws runtime_error exception if left operand and right operand are mismatching currencies.
		Return	New currency with summed values.
	*/

	Currency operator + (Currency const &currencyR);

	/*
		Currency operator - (Currency const &currencyR);

		Subtracts the value of two matching currencies via - operator

		Pre		Currency const &currencyR - The right operand
		Post	Both currencies' value are subtracted together.
				Overflowing coin values are carried over.
				Throws runtime_error exception if left operand and right operand are mismatching currencies.
		Return	New currency with subtracted values.
	*/

	Currency operator - (Currency const &currencyR);

	/*
		bool operator == (Currency const &currencyR);

		Checks if two matching currencies have equal values via == operator

		Pre		Currency const &currencyR - The right operand
		Post	Throws runtime_error exception if left operand and right operand are mismatching currencies.
		Return	True - values of both currencies are equal.
				False - values of both currencies are not equal.
	*/

	bool operator == (Currency const &currencyR);

	/*
		bool operator > (Currency const &currencyR);

		Checks if value of left currency is greater than the value of right currency via > operator

		Pre		Currency const &currencyR - The right operand
		Post	Throws runtime_error exception if left operand and right operand are mismatching currencies.
		Return	True - Value of left currency is greater than the value of right currency.
				False - Value of left currency is less than or equal to the value of right currency.
	*/

	bool operator > (Currency const &currencyR);

	/*
		bool operator < (Currency const &currencyR);

		Checks if value of left currency is less than the value of right currency via < operator

		Pre		Currency const &currencyR - The right operand
		Post	Throws runtime_error exception if left operand and right operand are mismatching currencies.
		Return	True - Value of left currency is less than the value of right currency.
				False - Value of left currency is greater than or equal to the value of right currency.
	*/

	bool operator < (Currency const &currencyR);

	/*
		std::istream& operator >> (std::istream &input, Currency &currency);

		Modifies the note value and coin value of the currency via the input stream.

		Pre		std::istream &input - The input stream.
				Currency const &currencyR - The currency object to modify.
		Post	Two inputs separated by whitespace are taken from the input stream.
				Note value and coin value are replaced with obtained values from input stream respectively.
				Overflowing coin values are carried over.
				Throws runtime_error exception if non-integer inputs are detected.
		Return	The input stream without the two inputs extracted from buffer.
	*/

	friend std::istream& operator >> (std::istream &input, Currency &currency);

	/*
		std::ostream& operator << (std::ostream &output, Currency const &currency);

		Prints the note value and coin value of the currency via the output stream.

		Pre		std::ostream &output - The output stream.
				Currency const &currencyR - The currency object to display.
		Post	The note value and coin value of the currency is inserted to the output stream.
		Return	The output stream with the note value and coin value of the currency in the buffer.
	*/

	friend std::ostream& operator << (std::ostream &output, Currency const &currency);
};


#endif
