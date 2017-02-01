class MyClass
{
	public:
		MyClass(int);
		MyClass();

		int myfunc(int); // External Function
		int test(int) {}; // Inline Function
		int x;

		MyClass operator+ (MyClass other) { // Inline
			MyClass newmc;
			newmc.x = this->x + other.x;
			return newmc;
		}

		MyClass operator- (MyClass); // External
};
