/* aoi-tag.cc */

#include "aoi-tag.h"

// PacketCreationTimeTag 구현
PacketCreationTimeTag::PacketCreationTimeTag () : m_creationTime (0)
{
}
PacketCreationTimeTag::PacketCreationTimeTag (uint64_t time) : m_creationTime (time)
{
}

void
PacketCreationTimeTag::SetCreationTime (uint64_t time)
{
  m_creationTime = time;
}

uint64_t
PacketCreationTimeTag::GetCreationTime () const
{
  return m_creationTime;
}

void
PacketCreationTimeTag::Serialize (TagBuffer i) const
{
  i.WriteU64 (m_creationTime);
}

void
PacketCreationTimeTag::Deserialize (TagBuffer i)
{
  m_creationTime = i.ReadU64 ();
}

uint32_t
PacketCreationTimeTag::GetSerializedSize () const
{
  return sizeof (uint64_t);
}

void
PacketCreationTimeTag::Print (std::ostream &os) const
{
  os << "CreationTime=" << m_creationTime;
}

TypeId
PacketCreationTimeTag::GetTypeId ()
{
  static TypeId tid =
      TypeId ("PacketCreationTimeTag").SetParent<Tag> ().AddConstructor<PacketCreationTimeTag> ();
  return tid;
}

TypeId
PacketCreationTimeTag::GetInstanceTypeId () const
{
  return GetTypeId ();
}

// PacketUeIdTag 구현
PacketUeIdTag::PacketUeIdTag () : m_ueId (0)
{
}
PacketUeIdTag::PacketUeIdTag (uint32_t ueId) : m_ueId (ueId)
{
}

void
PacketUeIdTag::SetUeId (uint32_t ueId)
{
  m_ueId = ueId;
}

uint32_t
PacketUeIdTag::GetUeId () const
{
  return m_ueId;
}

void
PacketUeIdTag::Serialize (TagBuffer i) const
{
  i.WriteU32 (m_ueId);
}

void
PacketUeIdTag::Deserialize (TagBuffer i)
{
  m_ueId = i.ReadU32 ();
}

uint32_t
PacketUeIdTag::GetSerializedSize () const
{
  return sizeof (uint32_t);
}

void
PacketUeIdTag::Print (std::ostream &os) const
{
  os << "UeId=" << m_ueId;
}

TypeId
PacketUeIdTag::GetTypeId ()
{
  static TypeId tid = TypeId ("PacketUeIdTag").SetParent<Tag> ().AddConstructor<PacketUeIdTag> ();
  return tid;
}

TypeId
PacketUeIdTag::GetInstanceTypeId () const
{
  return GetTypeId ();
}