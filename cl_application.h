#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H

#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_base.h"

using namespace std;

class cl_application : public cl_base {
public:
	cl_application();
	//   ~cl_application ( );

	void bild_tree_objects();
	int exec_app();
	static void signal_1(string&) {};
private:
	cl_1 * p_ob_1, *p_ob_11, *p_ob_12;
	cl_2 * p_ob_2, *p_ob_21, *p_ob_22;
	cl_3 * p_ob_3;
	cl_4 * p_ob_4;
};

#endif // CL_APPLICATION_H
