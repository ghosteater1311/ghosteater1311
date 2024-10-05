function run(a, b, c)
{
    var max;
    if ((a > b) && (a > c))
    {
        max = a;
    }
    else if ((b > a) && (b > c))
    {
        max = b;
    }
    else max = c; 
	console.log("The greatest number is " + max);
}
