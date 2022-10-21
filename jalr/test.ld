ENTRY(_start)

SECTIONS
{
	.instr 0 : AT(0)
	{
		* ( .text )
	}
}
