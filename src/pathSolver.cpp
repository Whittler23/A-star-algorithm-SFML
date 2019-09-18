#include "pathSolver.hpp"
#include "grid.hpp"

PathSolver::PathSolver()
	:mSolved(false)
	,mGridToSolve(nullptr)
{
}

void PathSolver::solveGrid(Grid& grid)
{
	mGridToSolve = &grid;

	while (mSolved == false)
	{

	}
}

void PathSolver::addStartingNode()
{
	mOpenNodes.emplace_back(mGridToSolve->getStartingNode());
}

void PathSolver::addClosingNode()
{
}
