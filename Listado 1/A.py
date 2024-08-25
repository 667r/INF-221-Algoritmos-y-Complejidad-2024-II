def final_position(n, commands):
    # Lista para guardar el historial de posiciones del huevo
    history = [0]  # Comienza en el niño 0
    
    i = 0
    while i < len(commands):
        command = commands[i]
        if command == "undo":
            # Si es comando undo, obtener el número de comandos a deshacer
            x = int(commands[i + 1])
            for _ in range(x):
                history.pop()
            i += 2  # Saltar el siguiente número (la cantidad de movimientos a deshacer)
        else:
            # Si es un comando de movimiento, actualizar la posición
            p = int(command)
            new_position = (history[-1] + p) % n
            history.append(new_position)
            i += 1  # Avanzar al siguiente comando
    
    # Devolver la última posición en la historia
    return history[-1]

# Ejemplo de uso basado en input del usuario:
if __name__ == "__main__":
    # Leer los valores de n y m desde la primera línea
    n, m = map(int, input().split())
    
    # Leer los comandos desde la segunda línea
    commands = input().split()
    
    # Llamar a la función y obtener la posición final
    result = final_position(n, commands)
    
    # Imprimir el resultado
    print(result)
