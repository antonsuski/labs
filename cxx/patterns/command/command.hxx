class command
{
public:
	command();
	virtual ~command();
	virtual ~exec(base_obj& o) = 0;
};
