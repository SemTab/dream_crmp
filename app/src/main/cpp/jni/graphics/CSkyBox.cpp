// -- INCLUDE`S
#include "CSkyBox.h"

#include "../game/game.h"
#include "../game/CVector.h"

#include "../net/netgame.h"
#include "../gui/gui.h"
#include "../game/common.h"
#include "../CSettings.h"

// -- EXTERN`S
extern CGame *pGame;
extern CNetGame *pNetGame;
extern CGUI *pGUI;
extern CSettings *pSettings;

// -- VARIABLE`S
CObject* CSkyBox::m_pSkyObject = nullptr;
RwTexture* pSkyTexture = nullptr;

const char *CSkyBox::m_TextureName = nullptr;

bool CSkyBox::m_bNeedRender = true;
float CSkyBox::m_fRotSpeed = 0.005f;

uint8_t pChangeTime;
// -- METHOD`S
MATRIX4X4* RwMatrixMultiplyByVector(VECTOR* out, MATRIX4X4* a2, VECTOR* in);

void CSkyBox::Initialise()
{
    if (!pSettings->GetReadOnly().iSkyBox)
        return;

    auto* dwModelArray = (uintptr_t*)(g_libGTASA +0x87BF48);
    if (!dwModelArray[18659])
        return;

    m_pSkyObject = CreateObjectScaled(18659, 1.3f);

    SetTexture("sky_weikton_da");
}

void CSkyBox::Process()
{
    if (!pSettings->GetReadOnly().iSkyBox)
        return;

    if (!m_pSkyObject)
        Initialise();

    if (m_pSkyObject)
    {
        CAMERA_AIM *aim = GameGetInternalAim();
        MATRIX4X4 matrix;

        m_pSkyObject->GetMatrix(&matrix);

        matrix.pos.X = aim->pos1x;
        matrix.pos.Y = aim->pos1y;
        matrix.pos.Z = aim->pos1z;

        RwMatrixRotate(&matrix, eAxis::Z, m_fRotSpeed);

        m_bNeedRender = true;

        ReTexture();

        m_pSkyObject->SetMatrix(matrix);
        m_pSkyObject->UpdateMatrix(matrix);
        m_pSkyObject->Render();

        m_bNeedRender = false;
    }
}

CObject* CSkyBox::CreateObjectScaled(int iModel, float fScale)
{
    auto *vecRot = new CVector();
    auto *vecScale = new CVector(fScale);

    if (!pNetGame)
        return nullptr;

    if(!pNetGame->GetObjectPool())
        return nullptr;

    auto *object = pGame->NewObject(iModel, 0.0f, 0.0f, 0.0f, vecRot->Get(), 0.0f);

    *(uint32_t*)((uintptr_t)object->m_pEntity + 28) &= 0xFFFFFFFE;
    *(uint8_t*)((uintptr_t)object->m_pEntity + 29) |= 1;

    object->RemovePhysical();

    MATRIX4X4 matrix;
    object->GetMatrix(&matrix);

    RwMatrixScale(&matrix, reinterpret_cast<VECTOR *>(vecScale));

    object->SetMatrix(matrix);
    object->UpdateRwMatrixAndFrame();

    *(uint8_t*)((uintptr_t)object->m_pEntity + 29) |= 1;
    object->AddPhysical();

    return object;
}

void CSkyBox::ReTexture()
{
    int iHours = pNetGame->m_byteWorldTime;

    if (pChangeTime != iHours)
    {
        pChangeTime = iHours;

        if (iHours >= 21 && iHours <= 5)
            SetTexture(weikton("sky_weikton_ni"));

        if (iHours >= 6 && iHours <= 10)
            SetTexture(weikton("sky_weikton_ev"));

        if (iHours >= 11 && iHours <= 18)
            SetTexture(weikton("sky_weikton_da"));

        if (iHours >= 19 && iHours <= 20)
            SetTexture(weikton("sky_weikton_ve"));
    }

    uintptr_t pAtomic = m_pSkyObject->m_pEntity->m_RwObject;
    if (!pAtomic)
        return;

    if (!*(uintptr_t*)(pAtomic + 4))
        return;

    ((void(*)())(g_libGTASA + 0x559EF8 + 1))();
    ((void*(*)())(g_libGTASA + 0x559FC8 + 1))();
    ((void(*)())(g_libGTASA + 0x559FEC + 1))();
    ((uintptr_t(*)(uintptr_t, uintptr_t, CObject*))(g_libGTASA +0x1AEE2C + 1))(*(uintptr_t*)(pAtomic + 4), (uintptr_t)RwFrameForAllObjectsCallback, m_pSkyObject); // RwFrameForAllObjects
}

uintptr_t CSkyBox::RwFrameForAllObjectsCallback(uintptr_t object, CObject* pObject)
{
    if (*(uint8_t*)object != 1)
        return object;

    uintptr_t pAtomic = object;
    RpGeometry* pGeom = *(RpGeometry * *)(pAtomic + 24);
    if (!pGeom)
        return object;

    int numMats = pGeom->matList.numMaterials;
    if (numMats > 16)
        numMats = 16;

    for (int i = 0; i < numMats; i++)
    {
        RpMaterial* pMaterial = pGeom->matList.materials[i];
        if (!pMaterial)
            continue;

        if (pSkyTexture)
            pMaterial->texture = pSkyTexture;
            pMaterial->color = RwRGBA {
                static_cast<RwUInt8>(g_libGTASA + 0x8C9360),
                static_cast<RwUInt8>(g_libGTASA + 0x8C92A8),
                static_cast<RwUInt8>(g_libGTASA + 0x8C91F0),
                150
            };
    }

    return object;
}

void CSkyBox::SetTexture(const char *texName)
{
    if (texName == nullptr)
        return;

    m_TextureName = texName;
    pSkyTexture = (RwTexture*)LoadTextureFromDB("samp", texName);
}

void CSkyBox::SetRotSpeed(float speed)
{
    m_fRotSpeed = speed;
}

bool CSkyBox::IsNeedRender()
{
    return m_bNeedRender;
}

CObject *CSkyBox::GetSkyObject()
{
    return m_pSkyObject;
}

