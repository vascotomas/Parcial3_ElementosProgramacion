# Parcial3_ElementosProgramacion
3er Parcial de la materia Elemento de Programación en UNLAM
Consigna:

-	La pinturería PINTURITAS que comercializa un máximo de 500 tipos de pinturas diferentes,
-	dispone del archivo “PINTURAS.dat”, donde cada registro contiene:
-	• Número de Artículo (entero, 5 cifras)
-	• Descripción (80 caracteres máximo)
-	• Unidades en stock (entero)
-	• Precio unitario (real)
-	Cada vez que se realiza una venta se ingresa por teclado, los siguientes datos:
-	• Número de Cliente (1 a 100) Función LEE_CONTROL
-	• Número de Artículo (entero, 5 cifras). Función LEE_CONTROL
-	• Cantidad de Unidades Vendidas. Función MAYORCERO.
-	Esta información termina con número de cliente igual a -1.
-	Si la cantidad de unidades vendidas es superior al stock existente del producto, NO se realizara la
-	venta y se guardara el registro ingresado por teclado en un archivo “FALTASTOCK.dat” con el
-	formato Numero de cliente, Numero de articulo y cantidad de unidades vendidas.
-	Se solicita confeccionar un programa que actualice el archivo “PINTURAS.dat” e informar:
-	a. La facturación total por cliente.
-	b. La cantidad de veces que cada cliente realizó una compra informando CLIENTE / CANTIDAD DE
-	COMPRAS, e informar el cliente que más compras realizo (el máximo es único)
-	c. Informar un listado de acuerdo con el siguiente diseño:
-	CLIENTE MONTO FACTURADO CANTIDAD DE VECES QUE REALIZÓ UNA COMPRA
-	 XXX XXX,XX XX
-	d. Informar un listado con los números de artículos los cuales no se pudo realizar alguna venta por
-	falta de stock.
-	e. Actualizar el archivo “PINTURAS.dat”, en UNIDADES en STOCK según las ventas ingresadas
