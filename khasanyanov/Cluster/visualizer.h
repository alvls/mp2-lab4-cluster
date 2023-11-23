#ifndef __VISUALIZER_H__
#define __VISUALIZER_H__

#include "cluster.h"
#include "console.h"

class Visualizer {
	Cluster cluster;
	Console console;
	void draw_cluster_load();
	void draw_status_fields();
public:
	void draw();
	Visualizer(Cluster c, Console con);
};


#endif
