public class ArrayList
{
public:
	ArrayList( Data data );
	ArrayList( const ArrayList * array );
	~ArrayList( );
protected:
	int length;
	Data data;
}

