#ifndef DEBRUIJN_IMPLEMENTATION_H
#define DEBRUIJN_IMPLEMENTATION_H

#include "slBenchmark.h"

#define DEBRUIJN_Z_SCALE 10000

#define DEBRUIJN_K 5
#define DEBRUIJN_N 3

#define DEBRUIJN_ALPHA 0.2
#define DEBRUIJN_BETA 0.8

#define DEBRUIJN_NUM_EDGES 124

#define DEBRUIJN_THRESHOLD 0

using namespace cv;

typedef struct {
	double score;
	int numberItems;
	int caseSigma;
} pairScore;

class DeBruijnImplementation : public slImplementation {
	public:
		DeBruijnImplementation();
		virtual ~DeBruijnImplementation() {};
		void preExperimentRun();
		void postExperimentRun();
		bool hasMoreIterations();
		virtual Mat generatePattern();
		void calculateCroppedCapture();
		virtual void postIterationsProcess();

	protected:
		void db(int, int, int, int, vector<int> &, vector<int> &);
		double clamp(double, double, double);
		double consistency(int, int);
		double score(Vec3s, Vec3s);
		double sigma(int, int, Vec3s *, Vec3s *, pairScore **);
		void populateCorrespondences(int, int, int[][2], pairScore **);
		Vec3s *transitions;
};

#endif //DEBRUIJN_IMPLEMENTATION_H