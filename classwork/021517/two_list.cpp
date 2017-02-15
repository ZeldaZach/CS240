List** two_lists(List *ll)
{
	List l_odd = new List(), l_even = new List();
	List ** retVal = new List*[2];

	for (int i = 0; ll != NULL; i++)
	{
		if (i % 2 == 1) // Odd
			l_odd << ll;
		else
			l_even << ll;

		ll = ll->next;
	}

	retVal[0] = l_odd;
	retVal[1] = l_even;

	return retVal;
}
