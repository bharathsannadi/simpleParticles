typedef struct
{
	float	x;
	float	y;
	float	z;
} Vector3f;

static inline Vector3f Vector3fMake(float inX, float inY, float inZ)
{
	Vector3f ret;
	ret.x = inX;
	ret.y = inY;
	ret.z = inZ;
	return ret;
}
static inline void Vector3fScaleAndAccumulate(Vector3f* accumulator, float scale, Vector3f* vectorToScale)
{
	accumulator->x += vectorToScale->x * scale;
	accumulator->y += vectorToScale->y * scale;
	accumulator->z += vectorToScale->z * scale;		
}
static inline void Vector3fSet(Vector3f *vector, float inX, float inY, float inZ)
{
    vector->x = inX;
    vector->y = inY;
    vector->z = inZ;
}
static inline float Vector3fMagnitude(Vector3f vector)
{
	return sqrtf((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z)); 
}
static inline float Vector3fDotProduct(Vector3f vector1, Vector3f vector2)
{		
	return vector1.x*vector2.x + vector1.y*vector2.y + vector1.z*vector2.z;
}
static inline void Vector3fScale(Vector3f* vectorToScale, float scale)
{
	vectorToScale->x *= scale;
	vectorToScale->y *= scale;
	vectorToScale->z *= scale;			
}
static inline void Vector3fRotateToDirection (float pitch, float azimuth, Vector3f *vector)
{
	vector->x = -sin(azimuth) * cos(pitch);
	vector->y = sin(pitch);
	vector->z = cos(pitch) * cos(azimuth);	
}

