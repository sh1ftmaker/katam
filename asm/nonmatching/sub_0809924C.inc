	.syntax unified
	.text

	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r2, _0809926C @ =gCurTask
	ldr r3, [r2]
	ldrh r1, [r3, #0x12]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08099270
	ldrh r0, [r3, #6]
	lsls r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #0x12
	adds r0, r0, r1
	b _08099278
	.align 2, 0
_0809926C: .4byte gCurTask
_08099270:
	ldrh r1, [r3, #6]
	movs r0, #0xc0
	lsls r0, r0, #0x12
	adds r0, r1, r0
_08099278:
	adds r5, r0, #0
	ldr r6, [r5, #0x44]
	ldrh r1, [r5, #6]
	movs r4, #0x80
	lsls r4, r4, #5
	adds r0, r4, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _08099296
	ldr r0, [r2]
	bl TaskDestroy
	b _0809959E
_08099296:
	adds r1, r6, #0
	cmp r6, #0
	beq _080992E0
	ldrb r0, [r6]
	cmp r0, #0
	beq _080992AE
	ldr r0, [r6, #8]
	ands r0, r4
	cmp r0, #0
	beq _080992AE
	str r3, [r5, #0x44]
	movs r1, #0
_080992AE:
	cmp r1, #0
	beq _080992E0
	ldr r0, _080992DC @ =gUnk_03000510
	ldrb r2, [r0, #4]
	adds r1, #0x56
	movs r0, #1
	ldrb r1, [r1]
	lsls r0, r1
	movs r1, #0x10
	orrs r0, r1
	ands r2, r0
	cmp r2, #0
	beq _08099350
	ldrh r1, [r5, #6]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _08099350
	adds r0, r5, #0
	bl sub_0803DBC8
	b _0809959E
	.align 2, 0
_080992DC: .4byte gUnk_03000510
_080992E0:
	adds r4, r5, #0
	movs r3, #0
	ldr r2, _08099348 @ =gKirbys
	adds r0, r2, #0
	adds r0, #0x60
	adds r1, r5, #0
	adds r1, #0x42
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08099322
	movs r3, #1
	movs r7, #0x82
	lsls r7, r7, #2
	adds r0, r2, r7
	ldrh r0, [r0]
	cmp r0, r1
	beq _08099322
	movs r3, #2
	movs r7, #0xec
	lsls r7, r7, #2
	adds r0, r2, r7
	ldrh r0, [r0]
	cmp r0, r1
	beq _08099322
	movs r3, #3
	movs r7, #0xab
	lsls r7, r7, #3
	adds r0, r2, r7
	ldrh r0, [r0]
	cmp r0, r1
	beq _08099322
	movs r3, #4
_08099322:
	ldr r0, _0809934C @ =gUnk_03000510
	ldrb r2, [r0, #4]
	movs r0, #1
	lsls r0, r3
	movs r1, #0x10
	orrs r0, r1
	ands r2, r0
	cmp r2, #0
	beq _08099350
	ldrh r1, [r4, #6]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _08099350
	adds r0, r4, #0
	bl sub_0803DBC8
	b _0809959E
	.align 2, 0
_08099348: .4byte gKirbys
_0809934C: .4byte gUnk_03000510
_08099350:
	ldr r0, _080993FC @ =gUnk_0203AD44
	ldrb r0, [r0]
	ldrh r1, [r5, #4]
	mov ip, r1
	cmp r0, #0
	beq _0809939C
	ldr r2, _08099400 @ =gCurLevelInfo
	mov r8, r2
	adds r1, r5, #0
	adds r1, #0x42
	ldrh r3, [r1]
	ldr r4, _08099404 @ =gUnk_02026D50
_08099368:
	subs r2, r0, #1
	movs r0, #0xcd
	lsls r0, r0, #3
	muls r0, r2, r0
	mov r7, r8
	adds r1, r0, r7
	movs r7, #0xbf
	lsls r7, r7, #3
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, r3
	bne _08099394
	adds r7, #0x66
	adds r0, r1, r7
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080993AE
_08099394:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08099368
_0809939C:
	movs r0, #1
	cmp r0, #0
	beq _080993AE
	ldrh r1, [r5, #6]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r5, #6]
_080993AE:
	mov r7, ip
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x20
	ble _080993BA
	b _080994EC
_080993BA:
	ldrh r2, [r5, #6]
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r2
	cmp r0, #0
	beq _08099442
	ldr r0, [r6, #8]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0809940C
	adds r0, r6, #0
	adds r0, #0xd4
	ldrh r1, [r0]
	cmp r1, #0x63
	beq _080993E6
	ldr r7, _08099408 @ =0x00000103
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #0xe
	bne _08099484
_080993E6:
	cmp r1, #0x36
	bne _080993EC
	b _0809959E
_080993EC:
	ldr r1, _08099408 @ =0x00000103
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xe
	beq _080993F8
	b _0809959E
_080993F8:
	b _08099484
	.align 2, 0
_080993FC: .4byte gUnk_0203AD44
_08099400: .4byte gCurLevelInfo
_08099404: .4byte gUnk_02026D50
_08099408: .4byte 0x00000103
_0809940C:
	ldr r0, _080994FC @ =0x0000FBFF
	ands r0, r2
	strh r0, [r5, #6]
	ldr r0, [r6, #0x44]
	ldr r1, _08099500 @ =0xFFFF6000
	adds r0, r0, r1
	str r0, [r5, #0x38]
	ldr r0, [r6, #0x40]
	adds r0, r0, r1
	str r0, [r5, #0x34]
	ldr r0, _08099504 @ =gUnk_0203AD3C
	adds r1, r6, #0
	adds r1, #0x56
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _08099442
	ldr r2, _08099508 @ =0x00000292
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl sub_0808AE30
	ldr r1, [r5, #0x34]
	str r1, [r0, #0x34]
	ldr r1, [r5, #0x38]
	str r1, [r0, #0x38]
_08099442:
	adds r0, r6, #0
	adds r0, #0xd4
	ldrh r1, [r0]
	cmp r1, #0x63
	beq _08099456
	ldr r7, _0809950C @ =0x00000103
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #0xe
	bne _08099470
_08099456:
	cmp r1, #0x36
	beq _08099464
	ldr r1, _0809950C @ =0x00000103
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xe
	beq _08099470
_08099464:
	ldr r0, [r6, #0xc]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	bne _0809952C
_08099470:
	ldr r2, _08099508 @ =0x00000292
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl sub_0808AE30
	ldr r1, [r5, #0x34]
	str r1, [r0, #0x34]
	ldr r1, [r5, #0x38]
	str r1, [r0, #0x38]
_08099484:
	ldr r1, _08099510 @ =gKirbys
	ldr r0, _08099504 @ =gUnk_0203AD3C
	ldrb r2, [r0]
	movs r0, #0xd4
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r0, r0, r1
	adds r0, #0x60
	adds r1, r6, #0
	adds r1, #0x60
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080994EC
	ldrb r0, [r6]
	cmp r0, #0
	bne _080994B0
	adds r0, r6, #0
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, r2
	bne _080994EC
_080994B0:
	ldr r1, _08099514 @ =gUnk_08D60FA4
	ldr r4, _08099518 @ =gSongTable
	ldr r2, _0809951C @ =0x0000107C
	adds r0, r4, r2
	ldrh r3, [r0]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r0, [r2, #4]
	cmp r0, #0
	blt _080994D4
	ldr r7, _08099520 @ =0x00001078
	adds r0, r4, r7
	ldr r1, [r0]
	ldrb r0, [r2, #9]
	ldrb r1, [r1, #2]
	cmp r0, r1
	bhi _080994EC
_080994D4:
	cmp r3, #0
	beq _080994E6
	ldr r0, _08099524 @ =gUnk_0203AD10
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080994EC
_080994E6:
	ldr r0, _08099528 @ =0x0000020F
	bl m4aSongNumStart
_080994EC:
	ldrh r1, [r5, #6]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r5, #6]
	b _0809959E
	.align 2, 0
_080994FC: .4byte 0x0000FBFF
_08099500: .4byte 0xFFFF6000
_08099504: .4byte gUnk_0203AD3C
_08099508: .4byte 0x00000292
_0809950C: .4byte 0x00000103
_08099510: .4byte gKirbys
_08099514: .4byte gUnk_08D60FA4
_08099518: .4byte gSongTable
_0809951C: .4byte 0x0000107C
_08099520: .4byte 0x00001078
_08099524: .4byte gUnk_0203AD10
_08099528: .4byte 0x0000020F
_0809952C:
	ldrh r0, [r5, #6]
	movs r3, #4
	orrs r3, r0
	strh r3, [r5, #6]
	ldr r4, _080995A8 @ =gUnk_0835104A
	movs r7, #4
	ldrsh r1, [r5, r7]
	movs r0, #0x20
	subs r0, r0, r1
	asrs r0, r0, #2
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x52
	ldrh r0, [r0]
	adds r2, r6, #0
	adds r2, #0xd2
	subs r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r5, #0x3e]
	ldrh r2, [r5, #4]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x12
	lsls r0, r0, #1
	adds r0, r0, r4
	adds r1, r6, #0
	adds r1, #0x50
	ldrh r1, [r1]
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r0, r6, #0
	adds r0, #0xd0
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r5, #0x3c]
	adds r2, #1
	strh r2, [r5, #4]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r3, r0
	cmp r3, #0
	bne _08099598
	movs r0, #0x3c
	ldrsh r1, [r5, r0]
	ldr r0, [r5, #0x34]
	adds r0, r0, r1
	str r0, [r5, #0x34]
	movs r2, #0x3e
	ldrsh r1, [r5, r2]
	ldr r0, [r5, #0x38]
	subs r0, r0, r1
	str r0, [r5, #0x38]
_08099598:
	adds r0, r5, #0
	bl sub_0806FAC8
_0809959E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080995A8: .4byte gUnk_0835104A

	.syntax divided
