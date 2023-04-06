# Algorithms for Calculating The Greatest Common Divisor and The Modular Inverse



### Identifying information

Yacine ELHAMER - 

### GCD algorithms

The greatest common divisor of two numbers is defined as a number which divides both of these numbers and that is a multiple of every shared divisor of these two numbers.

This number important in implementing many of the cryptographic algorithms we use today, therefore there is a great need for its computing algorithm to be as efficient as possible, which is what we are going to explore in this report; Specifically, the algorithms we will look at are The Euclidean algorithm, as well as The Extended Euclidean Algorithm.

### Euclidean Algorithm:

This algorithm is based primarily on the following rule: "The gcd of two numbers one of which is null, is the other number". Knowing this, and considering that the set of common divisors of _a_, _b_, and _a-b_ is the exact same (since the all get factored out in the substraction), we can reformulate the problem of trying to find _gcd(a, b)_ to trying to find _gcd(b, a-b)_ (where _a > b_); Furthermore, we could continue on reformulating the problem in same manner untill the problem becomes that of computing _gcd(d, 0)_, in which case we have found the gcd and it is equal to d. 

Additionally, in order for us to speed things up, we could omit code which checks for the larger number to use with the following iteration (i.e. should the next recrusive call be _gcd(a, a-b)_ or _gcd(b, b-a)_, as well as to skip several recursive calls, we could replace the substraction operation with the modulo operation; This is because the old gcd algorithm (the one using substraction) is essentially  going to be repeated until all multiples of _b_ are removed from _a_, only at which it starts making progress towards nullifying one of the terms, thereby find the gcd.

With this, a final recursive definition of this algorithm could be given as:

![gcd-algo](imgs/gcd-algo.png)



An implmentation of this in algorithm in C is as follows:

```C
int gcd(int a, int b) {
	return b != 0 ? gcd(b, a % b) : a;
}
```

The complexity of this algorithm is given by O(log min(a, b)).


### Extended Euclidean Algorithm:

This algorithm is a modification of the previous algorithm which helps us express the gcd in terms of the numbers _a_ and _b_; i.e. it gives us a solution for the following equation:

![gcd-equation](imgs/gcd-equation.png)

This algorithm works by setting the coefficients _x_ and _y_ to the values _1_ and _0_, and then working its way up the chain of recursive calls by replacing the _a mod b_ expression with _a - [a/b] b_, which is equivalent; This means that with each backwards iteration _n+1_ the coefficient of _a_ (which is _x \_ n+1_) is going to become _y\_n_, whole the coefficient of _b_ (which is _y\_n+1_) is going to become _x\_n - [a/b]\*y\_n _. With this we get a general sense of how this algorithm works.

An implementation of this function is as follows:

```C
int extended_gcd(int a, int b, int *x, int *y) {

	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}

	int x1, y1;
	int d = gcd(b, a % b, &x1, &y1);

	*x = y1;
	*y = x1 - y1 * (a / b);

	return d;
}
```

The complexity of this algorithm is O(log n)

### Modular Inverse:

The modular inverse of a number _a_ with regards to another number _m_ is defined as the number _x_ such that:

![mod-inverse](imgs/mod-inverse.png)

One requirement of this is that the numbers _a_ and _m_ have to be coprime, which is why it is often times most interesting to compute the modular inverses with regards to prime numbers.

An efficient way to find the modular inverse of a number would be to use the extended euclidean algorithm discussed previously. This is because since _a_ and _m_ are coprime, this means that _gcd(a, m) = 1_, therefore applying the extended euclidean algorithm gives us the integer coefficients _x_ and _y_ so that:

![mod-inverse-equation](imgs/mod-inverse-equation.png)

This means that the modular inverse in this case is equal to the number _x_ (since _- m \* y_ is a multiple of _m_).

An implementation of this algorithm is given in C as follows:

```C
int mod_inverse(int a, int m) {
	int x, y;

	if(extended_gcd(a, m, &x, &y) == 1)
		return x;
	else
		print("no modular inverse!");
}
```
