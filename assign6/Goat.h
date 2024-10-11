
class creature;

class goat : public creature
{
	public:
		goat(int);

		virtual ~goat();

		void endPass(int);

		int getPass() const;

		int getFoodPoint() const;

		void eatGrass();

	private:
		int foodPoint;
		int pass;
};
