class JavaVar
{
	static int global_var = 20;

	public static void foo(int x, int y)
	{
		System.out.print(x + " " + y + " ");
	}

	public static void main(String[] args)
	{
		foo(5,10);
		System.out.println(global_var);
	}
}