#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[])
{
	printf("Definition du prix de contrat CALL:\n");
	double share_price;
	double strike_price;
	double nb_days;
	const double VOLATILITY = 0.274;
	const double INTEREST_RATE = 0.015;
	const double pi = 3.14159265359;
	double contract_price;
	printf("Share price : ");
	scanf("%lf", &share_price);
	printf("Strike price :  ");
	scanf("%lf", &strike_price);
	printf("Number of days :  ");
	scanf("%lf", &nb_days);

	if (share_price < 0)
	{
		puts("Error, the share price must be greater than 0"); // 
	}
	else if (strike_price < 0)
	{ 
		puts("Error, the strike price must be greater than 0");
	}
	else if (nb_days < 0)
	{ 
		puts("Error, the number of days must be greater than 0");
	}
	else if (share_price > 1.7e308)
	{ 
		puts("Error Overflow, the share price must be less than 1.7e308");
	}
	else if (strike_price > 1.7e308)
	{ 
		puts("Error Overflow, the strike price must be less than 1.7e308");
	}
	else if (nb_days > 1.7e308)
	{ 
		puts("Error Overflow, the number of days must be less than 1.7e308");
	}
	else
	{
	
		double a1 = 0.319381530;
		double a2 = -0.356563782;
		double a3 = 1.781477937;
		double a4 = -1.821255978;
		double a5 = 1.330274429;
		double T = nb_days / 365.24;
		double d1 = (1 / (VOLATILITY * sqrt(T))) * (log(share_price / strike_price) + (INTEREST_RATE + (0.5) * pow(VOLATILITY, 2)) * T);
		double d2 = d1 - (VOLATILITY * sqrt(T));
		double k = 1 / (1 + 0.2316419 * d1);
		double k2 = 1 / (1 + 0.2316419 * d2);
		double N1 = 1 - (exp(-pow(d1, 2) / 2) / sqrt(2 * pi)) * (a1 * k + a2 * pow(k, 2) + a3 * pow(k, 3) + a4 * pow(k, 4) + a5 * pow(k, 5));
		double N2 = 1 - (exp(-pow(d2, 2) / 2) / sqrt(2 * pi)) * (a1 * k2 + a2 * pow(k2, 2) + a3 * pow(k2, 3) + a4 * pow(k2, 4) + a5 * pow(k2, 5));
		contract_price = share_price * N1 - (strike_price * exp(-INTEREST_RATE * T) * N2);

		printf("%.2lf $ \n",contract_price);
	}
}