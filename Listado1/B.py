def max_bungee_jump(N, heights):
    # Initialize the maximum possible jump distance
    max_distance = 0

    # Iterate over all pairs of mountains
    for i in range(N):
        for j in range(i + 1, N):
            # Determine the minimum height of the two mountains
            min_height = min(heights[i], heights[j])

            # Check the maximum height of the bridge
            # It should be above all mountains between i and j
            valid_bridge_height = min_height
            for k in range(i + 1, j):
                valid_bridge_height = min(valid_bridge_height, heights[k])
            
            # Compute the possible jumping distance
            distance = min_height - valid_bridge_height

            # Update the maximum distance
            if distance > max_distance:
                max_distance = distance
    
    return max_distance

# Read input values
n = int(input("Ingrese el número de montañas: "))  # Lee el número de montañas
heights = list(map(int, input("Ingrese las alturas de las montañas: ").split()))  # Lee las alturas de las montañas


# Compute the maximum bungee jumping distance
print(max_bungee_jump(n, heights))
