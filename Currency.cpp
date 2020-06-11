/*
	Lab 01A: Classes and Inheritance

	Lance Carrido

	This lab demonstrates classes and inheritance through a currency base class
	and five derived currency classes, as well as polymorphism through operator
	overloading.

	Assumption: Negative values on currencies are allowed.
*/

#include "Currency.h"
#include <fstream>

int Currency::getNoteValue() const
{
	return noteValue;
}

void Currency::setNoteValue(int noteValue)
{
	this->noteValue = noteValue;
}

int Currency::getCoinValue() const
{
	return coinValue;
}

void Currency::setCoinValue(int coinValue)
{
	this->coinValue = coinValue;
	roundCoinToNote();
}

std::string Currency::getNoteName() const
{
	return "Note";
}

std::string Currency::getCoinName() const
{
	return "Coin";
}

bool Currency::isMatchingCurrency(Currency const &currency) const
{
	return getNoteName() == currency.getNoteName() && getCoinName() == currency.getCoinName();
}

Currency Currency::operator + (Currency const &currencyR)
{
	if (isMatchingCurrency(currencyR))
	{
		int newNoteValue = noteValue + currencyR.getNoteValue();
		int newCoinValue = coinValue + currencyR.getCoinValue();
		return Currency(newNoteValue, newCoinValue);
	}
	else
	{
		throw std::runtime_error("Mismatched currencies.");
	}
}

Currency Currency::operator - (Currency const &currencyR)
{
	if (isMatchingCurrency(currencyR))
	{
		int newNoteValue = noteValue - currencyR.getNoteValue();
		int newCoinValue = coinValue - currencyR.getCoinValue();
		return Currency(newNoteValue, newCoinValue);
	}
	else
	{
		throw std::runtime_error("Mismatched currencies.");
	}
}

bool Currency::operator == (Currency const &currencyR)
{
	if (isMatchingCurrency(currencyR))
	{
		return noteValue == currencyR.getNoteValue() && coinValue == currencyR.getCoinValue();
	}
	else
	{
		throw std::runtime_error("Mismatched currencies.");
	}
}

bool Currency::operator > (Currency const &currencyR)
{
	if (isMatchingCurrency(currencyR))
	{
		if (noteValue > currencyR.getNoteValue())
		{
			return true;
		}
		else if (noteValue == currencyR.getNoteValue())
		{
			return coinValue > currencyR.getCoinValue();
		}
		return false;
	}
	else
	{
		throw std::runtime_error("Mismatched currencies.");
	}
}

bool Currency::operator < (Currency const &currencyR)
{
	if (isMatchingCurrency(currencyR))
	{
		if (noteValue < currencyR.getNoteValue())
		{
			return true;
		}
		else if (noteValue == currencyR.getNoteValue())
		{
			return coinValue < currencyR.getCoinValue();
		}
		return false;
	}
	else
	{
		throw std::runtime_error("Mismatched currencies.");
	}
}

void Currency::roundCoinToNote()
{
	if (coinValue >= 100) {
		while (coinValue >= 100)
		{
			noteValue++;
			coinValue -= 100;
		}
	}
	else if (coinValue < 0)
	{
		while (coinValue < 0)
		{
			noteValue--;
			coinValue += 100;
		}
	}
}

std::istream& operator >> (std::istream &input, Currency &currency)
{
	int noteValue;
	int coinValue;

	while (!input.eof())
	{
		//input >> noteValue >> coinValue;
		if(!(input >> noteValue >> coinValue))
		{
			std::ofstream log;
			log.open("log.txt", std::ios::app);
			std::cout << "Error, skipping invalid data!" << std::endl;
			log << "Error, skipping invalid data!" << std::endl;
			log.close();
			input.clear();
			input.ignore(100000, '\n');
		}
		else
		{
			currency.noteValue = noteValue;
			currency.setCoinValue(coinValue);
			return input;
		}
		

	}
	return input;
}

std::ostream& operator << (std::ostream &output, Currency const &currency)
{
	output << currency.getNoteName() << " " << currency.noteValue << " " << currency.coinValue << " " << currency.getCoinName() << std::endl;
	std::ofstream log;
	log.open("log.txt", std::ios::app);

	log << currency.getNoteName() << " " << currency.noteValue << " " << currency.coinValue << " " << currency.getCoinName() << std::endl;

	log.close();

	return output;
}