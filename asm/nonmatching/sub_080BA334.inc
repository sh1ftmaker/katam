	.syntax unified
	.text

	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x68]
	ldr r1, _080BA35C @ =0xFFFFFEFF
	ands r0, r1
	str r0, [r2, #0x68]
	adds r0, r2, #0
	adds r0, #0xb0
	ldr r0, [r0]
	ldrb r0, [r0, #0xe]
	cmp r0, #1
	beq _080BA354
	cmp r0, #1
	ble _080BA354
	cmp r0, #2
	beq _080BA360
_080BA354:
	adds r0, r2, #0
	bl sub_080BA4F0
	b _080BA366
	.align 2, 0
_080BA35C: .4byte 0xFFFFFEFF
_080BA360:
	adds r0, r2, #0
	bl sub_080BA5A4
_080BA366:
	pop {r0}
	bx r0
	.align 2, 0

	.syntax divided
