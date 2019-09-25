CColModel * __cdecl GetPedColModel_Func(CPed *pPed)
{
	if ( pPed->UseGroundColModel() )
		return &CTempColModels::ms_colModelPedGroundHit;
	else
		return ((CPedModelInfo *)CModelInfo::ms_modelInfoPtrs[pPed->m_nModelIndex])->m_pHitColModel;
}

typedef CColModel *( __cdecl *t_GetPedColModel_FuncCB)(CPed *pPed);
t_GetPedColModel_FuncCB GetPedColModelCB = GetPedColModel_Func;

CColModel *__cdecl GetPedColModel(CPed *pPed)
{
	return GetPedColModelCB(pPed);	
}

void EXP Set_GetPedColModel_CallBack(t_GetPedColModel_FuncCB func)
{
	GetPedColModelCB = func;
}

t_GetPedColModel_FuncCB EXP Get_GetPedColModel_CallBack()
{
	return GetPedColModelCB;
}

Bool __cdecl _ProcessLineOfSightSectorList_Func(CPtrList &ptrList, CColLine const &colLine, CColPoint &outColPoint, float &maxTouchDistance, CEntity *&outEntity, Bool doSeeThroughCheck, Bool doIgnoreCameraCheck)
{
	Bool bDeadPeds = false;
	float newTouchDist = maxTouchDistance;

	Bool bCarTyres = false;
	CColPoint wheelPoint;
	CColModel wheel;
	CColSphere aSpheres[6];
	
	if ( ptrList.m_pNode && CWorld::bIncludeDeadPeds && ptrList.m_pNode->pEntity->m_nType == 3 )
		bDeadPeds = true;

	if ( ptrList.m_pNode && CWorld::bIncludeCarTyres && ptrList.m_pNode->pEntity->m_nType == 2 )
	{
		bCarTyres = true;
		wheel.m_nNumTriangles = 0;
		wheel.m_pSpheres = aSpheres;
		wheel.m_nNumBoxes = 0;
		wheel.m_nNumSpheres = 6;
		wheel.m_nNumLines = 0;
	}
	
	CPtrNode *node = ptrList.m_pNode;
	while ( node )
	{
		CEntity *entity = node->pEntity;
		UInt32 scanCode = node->pEntity->m_nScanCode;
		node = node->pNext;

		if ( scanCode != CWorld::ms_nCurrentScanCode
			&& entity != CWorld::pIgnoreEntity
			&& (entity->m_bUsesCollision || bDeadPeds) )
		{
			if ( !doIgnoreCameraCheck || !CWorld::CameraToIgnoreThisObject(entity) )
			{
				CColModel *model = NULL;
				
				entity->m_nScanCode = CWorld::ms_nCurrentScanCode;
				
				float newTouchDist2 = newTouchDist;
				
				if ( entity->m_nType == 3 )
				{
					if ( entity->m_bUsesCollision || bDeadPeds && ((CPed *)entity)->m_nPedState == 49 )
						model = GetPedColModel((CPed *)entity);
					else
						model = NULL;
				}
				else if ( entity->m_bUsesCollision )
				{
					model = ((CBaseModelInfo *)CModelInfo::ms_modelInfoPtrs[entity->m_nModelIndex])->m_pColModel;
				}

				if ( model && CCollision::ProcessLineOfSight(colLine, entity->m_sCoords, *model, outColPoint, newTouchDist, doSeeThroughCheck) )
					outEntity = entity;
				
				if ( bCarTyres && ((CAutomobile *)entity)->SetUpWheelColModel(&wheel)
					&& CCollision::ProcessLineOfSight(colLine, entity->m_sCoords, wheel, wheelPoint, newTouchDist2, false) )
				{
					if ( newTouchDist2 < newTouchDist )
					{
						newTouchDist = newTouchDist2;
						outColPoint = wheelPoint;
						outEntity = entity;
					}
					else
					{
						float fLineDot = DotProduct(colLine.m_vEnd - colLine.m_vStart, entity->m_sCoords.right);
						float fPointDot = DotProduct(outColPoint.m_vecPosition - entity->m_sCoords.pos, entity->m_sCoords.right);

						if ( ( fLineDot < -0.85f && fPointDot > 0.0f ) || ( fLineDot > 0.85f && fPointDot < 0.0f ) )
						{
							newTouchDist = newTouchDist2;
							outColPoint = wheelPoint;
							outEntity = entity;
						}
					}
				}
			}
		}
	}

	wheel.m_pSpheres = NULL;
	
	if ( newTouchDist < maxTouchDistance )
	{
		maxTouchDistance = newTouchDist;
		return true;
	}
	return false;
}