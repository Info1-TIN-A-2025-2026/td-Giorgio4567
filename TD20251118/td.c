#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

double kmh_to_ms(double s_kmh);
double reaction_distance(double speed, double reaction_time);
double break_distance(double speed, double deceleration);
double total_stop_distance(double speed, double reaction_time, double deceleration);
bool stop_before_obstacle(double stop_distance, double obstacle_distance);

int main(int argc, const char *argv[])
{
	double speed_kmh = 0.;
	printf("Enter the speed (km/h): ");
	scanf("%lf", &speed_kmh);

	double reaction_time = 0.;
	printf("Enter the reaction time (s): ");
	scanf("%lf", &reaction_time);

	double deceleration = 0;
	printf("Enter the deceleration (m/s/s): ");
	scanf("%lf", &deceleration);
	
	double distance_obstacle = 0;
	printf("Enter the distance to the obstacle (m): ");
	scanf("%lf", &distance_obstacle);

	double stop_distance = total_stop_distance(speed_kmh, reaction_time, deceleration);
	printf("Total stop distance : %2.2lf m", stop_distance);
	if (stop_before_obstacle(stop_distance,distance_obstacle))
		printf(" => ✅ no collision\n");
	else
		printf(" => ❌ collision\n");
}

double kmh_to_ms(double s_kmh)
{
	assert(s_kmh >= 0);
	return s_kmh/3.6;
}

double reaction_distance(double speed, double reaction_time)
{
	assert(speed >= 0);
	assert(reaction_time >= 0);
	return speed * reaction_time;
}

double break_distance(double speed, double deceleration)
{
	assert(speed >= 0);
	assert(deceleration >= 0);
	return (speed * speed) / (2. * deceleration);
}

double total_stop_distance(double speed, double reaction_time, double deceleration)
{
	double v_ms = kmh_to_ms(speed);
	printf("Speed : %2.2lf km/h = %2.2lf m/s\n", speed, v_ms);
	double dist_react = reaction_distance(v_ms, reaction_time);
	printf("Reaction distance : %2.2lf m\n",dist_react);
	double dist_break = break_distance(v_ms, deceleration);
	printf("Break distance : %2.2lf m\n",dist_break);
	return dist_break + dist_react;
}

bool stop_before_obstacle(double stop_distance, double obstacle_distance)
{
	if (stop_distance < obstacle_distance)
		return 1;
	else
		return 0;
}