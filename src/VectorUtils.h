#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H

/**
 * Create a random vector with size constrained so that there are no repeating or missing values between arguments
 * @param p_StartValue
 * @param p_EndValue
 * @return
 */
std::vector<int> CreateRandomVector(std::size_t p_StartValue, std::size_t p_EndValue);

/**
 * Generate a linearly spaced vector with a number of points between a given range
 * Following MATLAB linspace function.
 * Credits: //https://gist.github.com/mortenpi/f20a93c8ed3ee7785e65
 * @param p_Vector Vector to convert to linear
 * @param p_StartValue Start value for the number range
 * @param p_EndValue End value for the number range
 * @param p_NumberOfPoints Number of values inside the vector
 */
void CreateLinearSpacedVector(std::vector<double>& p_Vector, int p_StartValue, int p_EndValue, std::size_t p_NumberOfValues);

#endif // VECTOR_UTILS_H