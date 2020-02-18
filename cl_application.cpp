#include "cl_application.h"
#include <iostream>
#include <string>
using namespace std;

cl_application::cl_application() { set_object_name("root"); }

void cl_application::bild_tree_objects() {
	p_ob_1 = new cl_1();
	p_ob_1 -> set_object_name("ob_1");
	p_ob_1->set_parent(this);

	p_ob_2 = new cl_2();
	p_ob_2->set_object_name("ob_2");
	p_ob_2->set_parent(p_ob_1);

	p_ob_3 = new cl_3();
	p_ob_3->set_object_name("ob_3");
	p_ob_3->set_parent(p_ob_2);

	p_ob_4 = new cl_4();
	p_ob_4->set_object_name("ob_4");
	p_ob_4->set_parent(p_ob_2);

	p_ob_21 = new cl_2();
	p_ob_21->set_object_name("ob_5");
	p_ob_21->set_parent(p_ob_1);

	p_ob_11 = new cl_1();
	p_ob_11->set_object_name("ob_6");
	p_ob_11->set_parent(this);

	p_ob_12 = new cl_1();
	p_ob_12->set_object_name("ob_7");
	p_ob_12->set_parent(this);

	p_ob_22 = new cl_2();
	p_ob_22->set_object_name("ob_8");
	p_ob_22->set_parent(p_ob_12);
}

int cl_application::exec_app() {
	show_tree((cl_base*)this, 0);
	p_ob_21->set_connect(SIGNAL_D(p_ob_1->signal_1), p_ob_21, HENDLER_D(cl_2::hendler_1));
	p_ob_21->set_connect(SIGNAL_D(p_ob_1->signal_2), p_ob_21, HENDLER_D(cl_2::hendler_2));
	p_ob_3->set_connect(SIGNAL_D(p_ob_1->signal_2), p_ob_3, HENDLER_D(cl_3::hendler_1));
	cout << endl;
	int st;
	string text; 
	do {
		cin >> st;
		switch (st) {
			case 1:
				cin >> text;
				p_ob_21->emit_signal(SIGNAL_D(p_ob_1->signal_1), text);
				break;
			case 2:
				cin >> text;
				p_ob_21->emit_signal(SIGNAL_D(p_ob_1->signal_2), text);
				break;
			case 3:
				cin >> text;
				p_ob_3->emit_signal(SIGNAL_D(p_ob_1->signal_2), text);
				break;
			default:
				break;
		}
	} while (st != 0);
	return 0;
}
