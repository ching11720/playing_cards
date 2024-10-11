

class creature
{
	public:
		creature();

		virtual ~creature();

		void older();
		
		int getAge() const;

		virtual void endPass(int)=0;

		virtual int getPass() const=0;

		virtual int getFoodPoint() const=0;

		virtual void eatGrass()=0;
	
	private:
		int age;
};
