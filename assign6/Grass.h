class creature;

class grass : public creature
{
	public:
		grass(int);

		virtual ~grass();

		void endPass(int );

		int getPass() const;

		int getFoodPoint() const;

		void eatGrass();

	private:
		int pass;
};
