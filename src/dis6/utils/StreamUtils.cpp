#include <dis6/utils/StreamUtils.h>

#include <dis6/EntityStatePdu.h>
#include <dis6/EntityID.h>
#include <dis6/DetonationPdu.h>

std::ostream& operator <<(std::ostream& lhs, const DIS::EntityType& rhs)
{
   lhs << "EntityType ("
       << (unsigned int)rhs.entityKind
       << "," << (unsigned int)rhs.domain
       << "," << (unsigned int)rhs.country
       << "," << (unsigned int)rhs.category
       << "," << (unsigned int)rhs.subcategory
       << ") ";
   return lhs;
}

std::ostream& operator <<(std::ostream& lhs, const DIS::EntityID& rhs)
{
   lhs << "EntityID ("
       << (unsigned int)rhs.entity << ") ";
   return lhs;
}

std::ostream& operator <<(std::ostream& lhs, const DIS::EntityStatePdu& rhs)
{
   lhs << "EntityStatePdu (" << rhs.entityID << ") ";
   return lhs;
}

std::ostream& operator <<(std::ostream& lhs, const DIS::DetonationPdu& rhs)
{
   lhs << "DetonationPDU (" << rhs.firingEntityID << ") ";
   return lhs;
}
